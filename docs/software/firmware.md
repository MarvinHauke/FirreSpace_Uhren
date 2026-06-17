# Firmware

## Geschwindigkeitskonstanten

In `src/main.cpp` sind zwei Faktoren (0.0–1.0) definiert:

```cpp
float SPEED_FACTOR_A = 0.3f;  // Stundenzeiger
float SPEED_FACTOR_B = 0.6f;  // Minutenzeiger
```

Beide Werte unabhängig einstellbar → ermöglicht absichtlich unterschiedliche Zeigergeschwindigkeiten.

## Externe Steuerung (Serial)

Laufzeit-Anpassung via USB/Serial (9600 Baud):

```
A<wert>   Beispiel: A0.5  → Motor A auf 50 %
B<wert>   Beispiel: B0.2  → Motor B auf 20 %
```

## Erweiterungsoptionen

| Option | Beschreibung |
|---|---|
| Potentiometer | Analogeingang (A0/A1) für physische Drehknöpfe |
| I²C / RS485 | Zentrale Steuerung mehrerer Einheiten |
| EEPROM | Werte persistent speichern |

## Architektur-Optionen (offen)

- **Eigenständig**: Jede Einheit läuft für sich (aktueller Stand)
- **Zentral**: Ein Master steuert mehrere TB6612FNG direkt → mehr Uhren bei weniger Nanos
