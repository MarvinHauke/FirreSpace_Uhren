# Stückliste

| # | Bauteil | Specs | Menge |
|---|---|---|---|
| 1 | Arduino Nano ATmega328 V3 | CH340, USB-C | nach Bedarf |
| 2 | TB6612FNG Motortreiber | Dual DC, max. 1,2 A/Kanal | nach Bedarf |
| 3 | Micro130 DC-Motor | 1,5–6 V, Welle ø 2 mm | 2× pro Uhr |
| 4 | LM2596S Step-Down | 3–40 V → 1,5–35 V, max. 3 A | nach Bedarf |
| 5 | IP55 Abzweigdose | 100×100×42 mm, Aufputz | 1× pro Uhr |
| 6 | 230 V → 9 V Netzteil | Steckernetzteil | nach Bedarf |

## Hinweise

- **LM2596S Ausgangsspannung** vor dem Einbau mit Multimeter auf Zielspannung einstellen.
- **TB6612FNG** versorgt beide Motoren; VM-Pin an Motorspannung (LM2596S-Ausgang), VCC an 5 V (Arduino).
- **Micro130**: Drehrichtung durch Polarität oder IN1/IN2-Pegel des TB6612FNG umkehrbar.
