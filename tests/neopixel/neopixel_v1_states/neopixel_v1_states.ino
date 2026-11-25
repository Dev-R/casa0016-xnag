// neopixel_v1_states.ino
// NeoPixel test v1: shows the three light states the nag will use,
// 5 seconds each: OFF, AMBER PULSING (cooking, fan off), GREEN STEADY (fan on).
// Wiring: DIN <- 470 ohm resistor <- pin 6, 5VDC <- 5V, GND <- GND.
//         Use the DIN end of the stick, not DOUT.
// Library: Adafruit NeoPixel (Library Manager).
#include <Adafruit_NeoPixel.h>

const int  PIN    = 6;
const int  NUM    = 8;            // 8 NeoPixel Stick
const int  BRIGHT = 40;           // 0-255. Kept low: 8 LEDs at full white draw ~0.5 A
// SK6812 sticks are often RGBW. If the colours look wrong or shifted, swap to NEO_GRB.
Adafruit_NeoPixel strip(NUM, PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.setBrightness(BRIGHT);
  strip.clear();
  strip.show();
  Serial.println("NeoPixel test start");
}

void fill(uint8_t r, uint8_t g, uint8_t b) {
  for (int i = 0; i < NUM; i++) strip.setPixelColor(i, strip.Color(r, g, b));
  strip.show();
}

void loop() {
  Serial.println("OFF");
  fill(0, 0, 0);
  delay(5000);

  Serial.println("AMBER PULSING");
  unsigned long start = millis();
  while (millis() - start < 5000) {
    float t = (millis() - start) / 1000.0;
    float level = 0.5 - 0.5 * cos(t * 2 * PI);   // smooth 0..1..0 once a second
    fill(255 * level, 120 * level, 0);
    delay(20);
  }

  Serial.println("GREEN STEADY");
  fill(0, 180, 0);
  delay(5000);
}
