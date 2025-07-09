# MQ-9 LPG Sensor Calibration Guide

## Why Calibrate?

Each MQ-9 sensor varies slightly. To ensure accuracy, we calculate Ro — the sensor's resistance in clean air — and use it as a baseline.

---

## Step-by-Step

1. Power the MQ-9 sensor for **24 hours** (heater burn-in)
2. Open the Arduino sketch and upload it
3. Open Serial Monitor at 9600 baud
4. Note the printed `Ro` value after calibration
5. Replace the `Ro = ...` line in your code with this calibrated value (optional if EEPROM not used)

---

## Clean Air Conditions

- Open room with no visible smoke, perfume, cooking gas
- Let sensor run for 2–5 minutes after power-on
- Run the calibration indoors, but away from walls or windows
