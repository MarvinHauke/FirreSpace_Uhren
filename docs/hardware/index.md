# Hardware — Übersicht

Jede Uhr besteht aus einem Arduino Nano, einem TB6612FNG Motortreiber und zwei Micro130 DC-Motoren (je einen für Stunden- und Minutenzeiger).

## Spannungsversorgung

```
230 V Netz
    └─ 230V→9V Netzteil
           └─ LM2596S Step-Down → Arduino (5 V via USB oder VIN)
           └─ LM2596S Step-Down → Motoren (einstellbar, z.B. 3–5 V)
```

Weiterführend: [Stückliste](komponenten.md) · [Schaltplan](schaltplan.md)
