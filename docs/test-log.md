# Test log

Dated evidence for the report's evaluation section. One row per test.

| Date | Step | What I tested | What I saw | Photo |
|---|---|---|---|---|
| 2026-11-25 | 2 | SGP30 header soldered, wired to Uno R3 (5 V, A4/A5) | Sensor found by the step 3 sketch; I2C scan skipped | |
| 2026-11-25 | 3 | SGP30 baseline in lab air, 1 reading/s | TVOC 0-2 ppb, eCO2 400-403 ppm | |
| 2026-11-25 | 3 | Hand sanitiser held ~10 cm away, then removed | Peak TVOC 41,038 ppb, eCO2 57,330 ppm (near the 60,000 ceiling). Fell to 3,700 ppb within 7 s of the first logged line. Time to peak and return to baseline not captured. | TODO plotter screenshot |
