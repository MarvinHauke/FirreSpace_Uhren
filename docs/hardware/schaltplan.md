# Schaltplan

Der Schaltplan wird mit **KiCAD** erstellt und liegt im Verzeichnis `hardware/kicad/` des Repositories.

## Pinbelegung (Arduino Nano ↔ TB6612FNG)

| Arduino Nano | TB6612FNG | Funktion |
|---|---|---|
| D4 | AIN1 | Motor A Richtung 1 |
| D5 | AIN2 | Motor A Richtung 2 |
| D6 (PWM) | PWMA | Motor A Geschwindigkeit |
| D7 | BIN1 | Motor B Richtung 1 |
| D8 | BIN2 | Motor B Richtung 2 |
| D9 (PWM) | PWMB | Motor B Geschwindigkeit |
| D3 | STBY | Standby (HIGH = aktiv) |
| 5V | VCC | Logikspannung TB6612FNG |
| GND | GND | Masse |

**VM** (Motorversorgung) des TB6612FNG wird separat vom LM2596S-Ausgang versorgt.

## KiCAD-Dateien

Sobald der Schaltplan fertig ist, sind die Dateien unter `hardware/kicad/` zu finden.
