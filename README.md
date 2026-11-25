# Extractor Nag

<!-- TODO: two or three sentences. What problem, for whom, and what the box does. Cite [1]. -->

A small box that sits on a cooker hood, notices cooking from the air, and nags when
the extractor fan is off.

> CASA0016 coursework, work in progress.

## Contents

- [Concept](#concept)
- [Design](#design)
- [Bringing it together](#bringing-it-together)
- [The code](#the-code)
- [Test scripts](#test-scripts)
- [Results](#results)
- [Demo](#demo)
- [Room for Progress](#room-for-progress)
- [References](#references)
- [Acknowledgements](#acknowledgements)

## Concept

<!-- TODO: motivation and the work of others (the report needs both). -->

## Design

<!-- TODO: flowchart of the states, then docs/svg/architecture.svg -->

| # | Block | What it does |
| :-: | ----- | ------------ |
| 1 | Sensing | TODO |
| 2 | Device | TODO |
| 3 | Network | TODO |
| 4 | Dashboard | TODO |

## Bringing it together

### What you need

| Part | Qty |
| ---- | :-: |
| Arduino MKR WiFi 1010 | 1 |
| Pimoroni SGP30 air quality breakout (PIM480) | 1 |
| Humidity and temperature breakout (TODO: exact part) | 1 |
| MPU-9250/6500 accelerometer breakout | 1 |
| Adafruit NeoPixel Stick, 8 LEDs | 1 |
| I2C OLED (TODO: exact part) | 1 |
| Push button, panel mount (16 mm) | 1 |
| Logic level converter | 1 |
| TODO: stripboard, magnets, enclosure | |

### Wiring

<!-- TODO: docs/svg/wiring.svg and a pin table -->

Everything logic-side runs on 3.3V, since the MKR1010's pins aren't 5V tolerant.

### The box

<!-- TODO: dimensions, files in docs/enclosure, photos -->

### Putting it together

<!-- TODO: numbered steps -->

## The code

The main sketch is in `src/extractor_nag`, split into tabs:

| File | Purpose |
| ---- | ------- |
| `extractor_nag.ino` | settings, `setup()` and `loop()` |
| `connections.ino`, `RGBLED.ino` | WiFi, MQTT and the status LED (adapted from the CASA0014 workshop code [TODO ref]) |

### Setting it up

1. Install the libraries from the Library Manager: WiFiNINA, PubSubClient (TODO: add sensor libraries).
2. Copy `arduino_secrets.example.h` to `arduino_secrets.h` and add your WiFi and MQTT
   details (it's git-ignored).
3. Upload.

## Test scripts

Built up one step at a time, so each part was proven before the next was added
(see [`tests`](tests)):

| # | Script | Proves |
| :-: | ------ | ------ |
| 1 | [`i2c_v1_scan`](tests/i2c/i2c_v1_scan) | the board can see each I2C part |

## Results

<!-- TODO: from docs/test-log.md. Detection counts, false alarms, recovery time with fan on vs off, current draw. -->

## Demo

<!-- TODO: video and photos -->

## Room for Progress

### Known limitations

### Next steps

## References

<!-- Harvard style in the report. Add every datasheet, library and source as you use it. -->

## Acknowledgements

- **Base code:** WiFi/MQTT connection handling adapted from the CASA0014 workshop
  sketch by Duncan Wilson, as reused in my own CASA0014 project.
- **AI assistance:** TODO, say what it was used for.
# casa0016-xnag
