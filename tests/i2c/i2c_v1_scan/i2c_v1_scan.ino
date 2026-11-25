// i2c_v1_scan.ino
// I2C test v1: lists every I2C device the MKR can see.
// Wiring: SDA to pin 11, SCL to pin 12, sensor power to VCC (3.3V), GND to GND.
#include <Wire.h>

void setup() {
  Serial.begin(115200);
  while (!Serial) {}          // MKR has native USB: wait for the monitor to open
  Wire.begin();
  Serial.println("Scanning I2C bus...");
  int found = 0;
  for (byte addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {   // 0 means a device answered
      Serial.print("Found device at 0x");
      Serial.println(addr, HEX);
      found++;
    }
  }
  Serial.print("Done. Devices found: ");
  Serial.println(found);
}

void loop() {}
