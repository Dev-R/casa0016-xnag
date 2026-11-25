// accel_v1_vibration.ino
// Accelerometer test v1: is the fan running? Prints a vibration level once a second.
// Board: MPU-9250/6500 breakout, read directly over I2C (no library needed).
// Wiring: VCC to 3.3V, GND to GND, SDA to A4 (Uno) or 11 (MKR), SCL to A5 (Uno) or 12 (MKR).
//         Leave AD0, INT, NCS, FSYNC, EDA, ECL unconnected (AD0 low = address 0x68).
// "Vibration" = how much the acceleration wobbles around its average in a 1 s window
// (standard deviation, in milli-g). Gravity alone gives about 1000 mg and no wobble.
#include <Wire.h>

const byte MPU = 0x68;
const int  N   = 200;            // samples per window, about 1 s

void writeReg(byte reg, byte val) {
  Wire.beginTransmission(MPU); Wire.write(reg); Wire.write(val); Wire.endTransmission();
}

byte readReg(byte reg) {
  Wire.beginTransmission(MPU); Wire.write(reg); Wire.endTransmission(false);
  Wire.requestFrom(MPU, (byte)1);
  return Wire.read();
}

// Total acceleration in milli-g, from the 3 axes (±2 g range: 16384 counts per g)
float readMag() {
  Wire.beginTransmission(MPU); Wire.write(0x3B); Wire.endTransmission(false);
  Wire.requestFrom(MPU, (byte)6);
  int16_t x = (Wire.read() << 8) | Wire.read();
  int16_t y = (Wire.read() << 8) | Wire.read();
  int16_t z = (Wire.read() << 8) | Wire.read();
  return sqrt((float)x * x + (float)y * y + (float)z * z) / 16.384;
}

void setup() {
  Serial.begin(9600);
  Wire.begin();
#if defined(ARDUINO_ARCH_AVR)
  // Uno only: Wire turns on internal pull-ups to 5 V. Switch them off so the
  // sensor's own pull-ups hold SDA/SCL at 3.3 V, which is safe for the MPU.
  digitalWrite(SDA, LOW);
  digitalWrite(SCL, LOW);
#endif
  delay(100);
  writeReg(0x6B, 0x00);          // PWR_MGMT_1: wake the chip from sleep
  delay(100);
  byte who = readReg(0x75);      // WHO_AM_I: 0x71 = MPU-9250, 0x70 = MPU-6500
  Serial.print("Accelerometer test start, WHO_AM_I = 0x");
  Serial.println(who, HEX);
  if (who == 0x00 || who == 0xFF) {
    Serial.println("MPU not found, check wiring");
    while (true) {}
  }
}

void loop() {
  float first = readMag();       // subtract the first sample to keep the maths accurate
  float sum = 0, sumSq = 0;
  for (int i = 0; i < N; i++) {
    float d = readMag() - first;
    sum += d; sumSq += d * d;
    delay(4);
  }
  float mean = sum / N;
  float vib  = sqrt(max(0.0, sumSq / N - mean * mean));
  Serial.print("vib_mg:"); Serial.println(vib, 1);
}
