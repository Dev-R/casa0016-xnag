// humidity_v1_read.ino
// Humidity test v1: temperature and humidity once a second (HTU21D/SHT21/Si7021, address 0x40).
// Wiring: Vdd to 3.3V (never 5V), GND to GND, SDA to A4 (Uno) or 11 (MKR), SCL to A5 (Uno) or 12 (MKR).
#include <Wire.h>
const byte ADDR = 0x40;

uint16_t readRaw(byte cmd, int waitMs) {
  Wire.beginTransmission(ADDR); Wire.write(cmd); Wire.endTransmission();
  delay(waitMs);                               // the chip needs time to measure
  Wire.requestFrom(ADDR, (byte)3);             // 2 data bytes + 1 checksum
  uint16_t raw = (Wire.read() << 8) | Wire.read();
  Wire.read();                                 // checksum, ignored for now
  return raw & 0xFFFC;                         // bottom 2 bits are status, not data
}

void setup() {
  Serial.begin(9600);
  Wire.begin();
#if defined(ARDUINO_ARCH_AVR)
  digitalWrite(SDA, LOW);                      // Uno: turn off the 5 V internal pull-ups
  digitalWrite(SCL, LOW);
#endif
  delay(100);
  Serial.println("Humidity test start");
  Wire.beginTransmission(ADDR);
  if (Wire.endTransmission() != 0) {
    Serial.println("Nothing at 0x40. Devices found:");
    for (byte a = 1; a < 127; a++) {
      Wire.beginTransmission(a);
      if (Wire.endTransmission() == 0) { Serial.print(" 0x"); Serial.println(a, HEX); }
    }
    while (true) {}
  }
}

void loop() {
  float t  = -46.85 + 175.72 * readRaw(0xF3, 85) / 65536.0;   // datasheet formula
  float rh = -6.0   + 125.0  * readRaw(0xF5, 30) / 65536.0;
  Serial.print("temp_C:"); Serial.print(t, 1);
  Serial.print(" RH_pct:"); Serial.println(rh, 1);
  delay(1000);
}
