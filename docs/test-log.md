# Test log

Dated evidence for the report's evaluation section. One row per test.

| Date | Step | What I tested | What I saw | Photo |
|---|---|---|---|---|
| 2026-11-25 | 2 | SGP30 header soldered, wired to Uno R3 (5 V, A4/A5) | Sensor found by the step 3 sketch; I2C scan skipped | |
| 2026-11-25 | 3 | SGP30 baseline in lab air, 1 reading/s | TVOC 0-2 ppb, eCO2 400-403 ppm | |
| 2026-11-25 | 3 | Hand sanitiser held ~10 cm away, then removed | Peak TVOC 41,038 ppb, eCO2 57,330 ppm (near the 60,000 ceiling). Fell to 3,700 ppb within 7 s of the first logged line. Time to peak and return to baseline not captured. | [setup](images/step03-sgp30-sanitiser-test.jpg), TODO plotter screenshot |
| 2026-11-25 | 5 | MPU accelerometer on Uno, 40 mm 5 V fan resting on the breadboard, 1 s std-dev windows | Off ~4 mg; fan on 43-54 mg (~12x off). One knock on the table: a single 132.8 mg window, back to 4.6 mg the next second. Knock is higher than the fan but lasts one window; the fan stays high. Fan was held by hand against the breadboard, so hand movement may add to the 'on' reading: recheck with the fan resting, not held. | [setup](images/step05-accel-fan-test.jpg) |
