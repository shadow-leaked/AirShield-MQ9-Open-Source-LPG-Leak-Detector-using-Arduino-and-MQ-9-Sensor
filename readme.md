# 🔥 MQ-9 LPG Gas Detector using Arduino

An open-source, professionally structured LPG detection system using the MQ-9 sensor — complete with real-time monitoring, buzzer alerts, and LED indicators. Developed and maintained by [TechNode Systems].

---

### ⚙️ Features

- ✅ Calibrated LPG gas detection (based on MQ-9 sensitivity curve)
- ✅ Real-time ppm estimation using Rs/Ro ratio
- ✅ Buzzer + Red LED alert on gas leak
- ✅ Green LED for safe environment
- ✅ Modular, documented, and extendable codebase

---

### 🔧 Hardware Requirements

| Component          | Quantity |
|-------------------|----------|
| MQ-9 Gas Sensor    | 1        |
| Arduino UNO/Nano   | 1        |
| Red LED            | 1        |
| Green LED          | 1        |
| Buzzer (5V)        | 1        |
| 220Ω Resistors     | 2        |
| Breadboard + Wires | 1 set    |

---

### 🚀 Getting Started

1. Power MQ-9 sensor continuously for **24 hours** (first-time burn-in)
2. Upload the sketch from `/Arduino/MQ9_LPG_Detector.ino`
3. Open Serial Monitor at 9600 baud
4. Observe `Ro` calibration value
5. Gas detection begins — red LED + buzzer will trigger if LPG > threshold

> For accurate calibration, follow [Calibration Guide](docs/MQ9_Calibration_Guide.md)

---

### 🧠 LPG Gas Curve Used

We approximate MQ-9's LPG response with:
- `log10(ppm)` = -2.1 * log10(Rs/Ro) + 0.72

Where:
- `Rs` = sensor resistance in current air
- `Ro` = sensor resistance in clean air

---

### © License
This project is licensed under the **MIT License**.  
Maintained with ❤️ by **Aditya Sharma/ NIELIT Imphal, Drone Electronics**
