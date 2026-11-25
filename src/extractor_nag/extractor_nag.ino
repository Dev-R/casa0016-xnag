/*
 * extractor_nag.ino
 *
 * Purpose:
 * Main program for Extractor Nag, a box on a cooker hood that notices
 * cooking from the air and nags when the extractor fan is off.
 *
 * STATUS: scaffold only. Each tab below is added after its test sketch
 * in /tests works on its own.
 *
 * Project Structure (planned):
 * - air.ino          SGP30 (TVOC) and humidity/temperature readings.
 * - fan.ino          Accelerometer: is the hood fan running?
 * - state.ino        States: WARMING UP, IDLE, COOKING, NAGGING, MUTED, OFFLINE.
 * - lights.ino       Neopixel stick: off, pulsing amber, steady green.
 * - screen.ino       OLED: one big word for the state.
 * - connections.ino  WiFi and MQTT connections.
 * - RGBLED.ino       Onboard status LED.
 *
 * Notes:
 * - All logic pins are 3.3V. The MKR WiFi 1010 is not 5V tolerant.
 * - The device must keep nagging with no WiFi. Never block loop() on the network.
 *
 * Base WiFi/MQTT code: Duncan Wilson (CASA)
 * https://github.com/ucl-casa-ce/casa0014/tree/c900cddbd06d88c26d0962312b30b779e8cc97f2/vespera
 */

#include <SPI.h>
#include <WiFiNINA.h>
#include <PubSubClient.h>
#include "arduino_secrets.h"   // copy arduino_secrets.example.h, never commit the real one
#include <utility/wifi_drv.h>
#include <Wire.h>

const char* ssid          = SECRET_SSID;
const char* password      = SECRET_PASS;
const char* mqtt_username = SECRET_MQTTUSER;
const char* mqtt_password = SECRET_MQTTPASS;
const char* mqtt_server   = "mqtt.cetools.org";   // TODO: confirm the broker for CASA0016
const int mqtt_port       = 1884;

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

String mqtt_topic = "student/CASA0016/extractor-nag";   // TODO: confirm the topic
String clientId = "";   // unique client ID, built from the MAC address in setup()

// Pin plan (confirmed one by one in /tests)
const int BUTTON_PIN   = 4;   // mute button to GND, internal pull-up
const int NEOPIXEL_PIN = 6;   // data to the stick's DIN, through a level converter
// I2C on SDA 11 / SCL 12: SGP30 0x58, humidity sensor, accelerometer 0x68, OLED 0x3C

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Wire.begin();

  // Status LED on the MKR1010 NINA module
  WiFiDrv::pinMode(25, OUTPUT); // R
  WiFiDrv::pinMode(26, OUTPUT); // G
  WiFiDrv::pinMode(27, OUTPUT); // B
  LedRed();

  // Unique client ID from the MAC address
  byte mac[6];
  WiFi.macAddress(mac);
  char macStr[18];
  snprintf(macStr, sizeof(macStr), "%02X%02X%02X%02X%02X%02X", mac[5], mac[4], mac[3], mac[2], mac[1], mac[0]);
  clientId = "ExtractorNag_" + String(macStr);

  // Network is added at steps 9 and 10:
  // startWifi();
  // mqttClient.setServer(mqtt_server, mqtt_port);
}

void loop() {
  // 1. read air        (air.ino)
  // 2. read fan        (fan.ino)
  // 3. update state    (state.ino)
  // 4. lights + screen (lights.ino, screen.ino)
  // 5. publish         (connections.ino), only if connected
}
