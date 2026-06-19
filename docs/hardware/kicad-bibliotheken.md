# KiCAD Bibliotheken einbinden

## Empfohlene externe Bibliotheken

| Bibliothek | Inhalt | Relevant für |
|---|---|---|
| SparkFun KiCAD Libraries | Symbols + Footprints | TB6612FNG, allg. Breakouts |
| Adafruit KiCAD Library | Symbols + Footprints | Alternative Breakout-Footprints |

---

## SparkFun Bibliothek einbinden

### 1. Repository klonen

```bash
git clone https://github.com/sparkfun/SparkFun-KiCad-Libraries
```

Empfohlener Ablageort: außerhalb des Projektverzeichnisses, z.B. `~/kicad-libraries/SparkFun-KiCad-Libraries`.

### 2. Symbol-Bibliothek hinzufügen

1. KiCAD öffnen → **Preferences → Manage Symbol Libraries**
2. Tab **Global Libraries** → `+` (Zeile hinzufügen)
3. Felder ausfüllen:

| Feld | Wert |
|---|---|
| Nickname | `SparkFun` |
| Library Path | `<pfad>/SparkFun-KiCad-Libraries/KiCad Symbols/SparkFun.kicad_sym` |
| Plugin Type | KiCad |

4. **OK**

### 3. Footprint-Bibliothek hinzufügen

1. **Preferences → Manage Footprint Libraries**
2. Tab **Global Libraries** → `+`
3. Felder ausfüllen:

| Feld | Wert |
|---|---|
| Nickname | `SparkFun` |
| Library Path | `<pfad>/SparkFun-KiCad-Libraries/KiCad Footprints/SparkFun.pretty` |
| Plugin Type | KiCad |

4. **OK**

---

## Adafruit Bibliothek einbinden

Gleiche Vorgehensweise:

```bash
git clone https://github.com/adafruit/Adafruit_KiCad_Library
```

Dann analog wie SparkFun unter **Manage Symbol Libraries** und **Manage Footprint Libraries** eintragen. Nickname: `Adafruit`.

---

## Bauteile aus den Bibliotheken

Die folgenden Bauteile des Projekts sind in den Standardbibliotheken von KiCAD bereits vorhanden:

| Bauteil | Bibliothek | Symbol-Name |
|---|---|---|
| Arduino Nano | KiCAD Standard (`MCU_Module`) | `Arduino_Nano` |
| LM2596S | KiCAD Standard (`Regulator_Switching`) | `LM2596S-5` / `LM2596S-ADJ` |
| TB6612FNG (IC) | KiCAD Standard (`Motor_Driver`) oder SparkFun | `TB6612FNG` |
| Anschlussklemmen | KiCAD Standard (`Connector`) | `Screw_Terminal_*` |

Der **Micro130 Motor** hat kein Standard-Symbol — ein generisches 2-Pin-Bauteil (`Device:Motor_DC`) ist ausreichend.

---

## Tipp: Projektlokale Bibliotheken

Sollen die Bibliotheken direkt im Repository liegen (z.B. als Git-Submodule), können sie auch als **projektlokale Bibliotheken** eingebunden werden:

```bash
# Im Projektverzeichnis:
git submodule add https://github.com/sparkfun/SparkFun-KiCad-Libraries hardware/kicad/lib/SparkFun
```

Dann in KiCAD unter dem Tab **Project Libraries** statt **Global Libraries** eintragen. Vorteil: Bibliothek ist für alle Nutzer des Repos direkt verfügbar.
