# Tests

Incremental test sketches for Extractor Nag. Each proves one thing before the next part is added.

| # | Test | Purpose | Result |
|---|------|---------|--------|
| 1 | `i2c/i2c_v1_scan` | The MKR can see each I2C part at its address | |
| 2 | `sgp30/sgp30_v1_read` | SGP30 gives TVOC and eCO2, and reacts to hand sanitiser | Works: baseline 0-2 ppb, sanitiser peak 41,038 ppb, fast decay |
| 3 | `neopixel/neopixel_v1_states` | The stick shows the three nag states: off, amber pulsing, green steady | Skipped: tested in the lab this week |
| 4 | `accel/accel_v1_vibration` | The accelerometer can tell the fan on from off, and from a knock on the table | Works: off ~4 mg, on 43-54 mg, knock one 133 mg spike |
| 5 | `humidity/humidity_v1_read` | Humidity board reads temperature and RH, and rises with breath or steam | |

## Wiring
- **I2C (all sensors and the OLED)**: SDA to pin 11, SCL to pin 12, power from VCC (3.3V)
