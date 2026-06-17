# Software — Übersicht

Der Code liegt unter `src/main.cpp` und wird mit **PlatformIO** gebaut und geflasht.

## PlatformIO Setup

```bash
# Abhängigkeiten installieren & kompilieren
pio run

# Auf Arduino Nano flashen
pio run --target upload

# Seriellen Monitor öffnen (9600 Baud)
pio device monitor
```

## Geschwindigkeit anpassen

Über den seriellen Monitor können die Motordrehzahlen zur Laufzeit geändert werden:

```
A0.3   → SPEED_FACTOR_A (Stundenzeiger) auf 30 %
B0.7   → SPEED_FACTOR_B (Minutenzeiger) auf 70 %
```

Für dauerhafte Änderungen die Konstanten in `src/main.cpp` anpassen: [→ Firmware](firmware.md)
