# FirreSpace Uhren

Kunstinstallation für FirreSpace 2026: Analoge Uhren mit DC-Motoren, gesteuert von Arduino Nano.

Die Uhren zeigen keine korrekte Zeit — Zeigergeschwindigkeiten sind bewusst variabel und unterschiedlich eingestellt.

## Komponenten (Überblick)

| Komponente | Funktion |
|---|---|
| Arduino Nano ATmega328 (CH340) | Mikrocontroller |
| TB6612FNG | Dual DC Motortreiber |
| Micro130 DC-Motor (1,5–6 V) | Zeiger-Antrieb |
| LM2596S Step-Down | Spannungsregler 9 V → Motorspannung |
| IP55 Abzweigdose 100×100×42 mm | Gehäuse |
| 230 V → 9 V Netzteil | Stromversorgung |

## Schnellstart

```bash
# Firmware flashen (PlatformIO)
pio run --target upload

# Dokumentation lokal starten
mkdocs serve
```

Weitere Details in den Unterabschnitten.
