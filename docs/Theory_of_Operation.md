# MQ-9 Theory of Operation (LPG Focused)

The MQ-9 sensor detects gases by changing its internal resistance (Rs) based on gas concentration. It uses a tin dioxide (SnO₂) surface heated to ~300°C.

---

## Key Formula

We use the LPG curve from the MQ-9 datasheet:
- `log10(ppm)` = -2.1 * log10(Rs/Ro) + 0.72
- `Ro` is sensor resistance in clean air
- `Rs` is current sensor resistance
- The ratio `Rs/Ro` decreases as LPG concentration increases

---

## Limitations

- Not suitable for medical or life-critical use
- Affected by humidity, temperature, and pressure
- LPG is heavier than air — always mount sensor near the floor
