# Aufbau-Anleitung

## Werkzeug & Material

- Lötkolben, Lötzinn
- Multimeter
- Schraubendreher (Kreuz + Schlitz)
- Kabelbinder, Schrumpfschlauch

## Schritt 1 — Spannungsversorgung

1. 230 V → 9 V Netzteil anschließen.
2. LM2596S Step-Down-Ausgang mit Multimeter auf Zielspannung einstellen (Motoren: 3–5 V; Arduino via VIN: 7–12 V oder via 5V-Reg.).
3. Ausgangsspannung sichern, bevor Bauteile angeschlossen werden.

## Schritt 2 — TB6612FNG verdrahten

Pinbelegung → [Schaltplan](../hardware/schaltplan.md)

- **VCC** → 5 V (vom Arduino-5V-Pin)
- **VM** → Motorspannung (LM2596S-Ausgang)
- **STBY** → HIGH (D3 am Arduino)

## Schritt 3 — Motoren anschließen

- Motor A (Stundenzeiger) → AO1 / AO2
- Motor B (Minutenzeiger) → BO1 / BO2
- Drehrichtung ggf. durch Tauschen der Kabel korrigieren.

## Schritt 4 — Arduino programmieren

```bash
pio run --target upload
```

## Schritt 5 — Test

1. Seriellen Monitor öffnen (`pio device monitor`).
2. Geschwindigkeiten per `A0.3` / `B0.6` testen.
3. Zeiger mechanisch befestigen.

## Schritt 6 — Einbau in IP55-Gehäuse

- Kabeleinführungen mit passenden Kabelverschraubungen abdichten.
- Alle Verbindungen auf festen Sitz prüfen.
- Deckel schließen und Funktion nochmals verifizieren.
