# Tests

Incremental test sketches for Extractor Nag. Each proves one thing before the next part is added.

| # | Test | Purpose | Result |
|---|------|---------|--------|
| 1 | `i2c/i2c_v1_scan` | The MKR can see each I2C part at its address | |
| 2 | `sgp30/sgp30_v1_read` | SGP30 gives TVOC and eCO2, and reacts to hand sanitiser | Works: baseline 0-2 ppb, sanitiser peak 41,038 ppb, fast decay |

## Wiring
- **I2C (all sensors and the OLED)**: SDA to pin 11, SCL to pin 12, power from VCC (3.3V)
