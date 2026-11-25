// sgp30_v1_read.ino
// SGP30 test v1: prints TVOC and eCO2 once a second.
// Wiring: SDA/SCL to the board's I2C pins (MKR: 11/12, Uno: A4/A5),
//         2-6V to 3.3V (MKR) or 5V (Uno), GND to GND.
// Library: Adafruit SGP30 Sensor (Library Manager).
// Serial Monitor: set the speed (bottom right) to 9600 baud to match BAUD below.
#include <Wire.h>
#include "Adafruit_SGP30.h"

const long BAUD = 9600;     // the IDE's default speed, so the monitor matches out of the box
Adafruit_SGP30 sgp;

void setup() {
  Serial.begin(BAUD);
  while (!Serial && millis() < 3000) {}   // MKR waits for the monitor, Uno carries on
  delay(500);                             // let the line settle before the first text
  Serial.println();
  Serial.println("SGP30 test start");
  if (!sgp.begin()) {                     // starts the sensor's air-quality algorithm
    Serial.println("SGP30 not found, check wiring");
    while (true) {}
  }
  Serial.println("Warming up: TVOC 0 / eCO2 400 for about 15 s is normal");
}

void loop() {
  if (sgp.IAQmeasure()) {                 // the datasheet asks for one reading per second
    Serial.print("TVOC_ppb:");  Serial.print(sgp.TVOC);
    Serial.print(" eCO2_ppm:"); Serial.println(sgp.eCO2);
  } else {
    Serial.println("read failed");
  }
  delay(1000);
}
