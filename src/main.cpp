#include <Arduino.h>

// Ersetzt den 32.768-kHz-Quarz eines Quarz-Uhrwerks durch ein per Timer1
// erzeugtes Rechtecksignal mit einstellbarer Frequenz. Der Uhrwerk-IC selbst
// bleibt verbaut und zählt die Pulse wie gewohnt herunter — er läuft nur
// proportional zur eingespeisten Frequenz schneller/langsamer. Pin 9 (OC1A)
// verbindet sich mit dem Oszillatoreingang des Uhrwerk-ICs; der Quarz wird
// dafür abgeklemmt/entfernt. Kein TB6612FNG, kein H-Brücken-Ansteuern.
#define OSC_OUT_PIN 9 // OC1A

const double NOMINAL_FREQ_HZ = 32768.0;
float speedFactorA = 2.4f; // 1.0 = normale Geschwindigkeit

void setOscillatorFrequency(double freqHz) {
  // Timer1 Toggle-Modus: f_out = F_CPU / (2 * prescaler * (1 + OCR1A)),
  // Prescaler = 1
  double ocr = (F_CPU / (2.0 * freqHz)) - 1.0;
  if (ocr < 1.0)
    ocr = 1.0;
  if (ocr > 65535.0)
    ocr = 65535.0;
  OCR1A = (uint16_t)(ocr + 0.5);
}

void setup() {
  pinMode(OSC_OUT_PIN, OUTPUT);

  // Timer1: CTC-Modus (WGM12), Toggle von OC1A bei Compare Match (COM1A0),
  // Prescaler = 1 (CS10)
  TCCR1A = (1 << COM1A0);
  TCCR1B = (1 << WGM12) | (1 << CS10);
  setOscillatorFrequency(NOMINAL_FREQ_HZ * speedFactorA);

  Serial.begin(9600);
}

void loop() {
  // Geschwindigkeit per Serial anpassen: "A1.5" setzt das Uhrwerk auf das
  // 1.5-fache der normalen Geschwindigkeit
  if (Serial.available()) {
    char motor = Serial.read();
    float val = Serial.parseFloat();
    if (motor == 'A' && val > 0.0f) {
      speedFactorA = val;
      setOscillatorFrequency(NOMINAL_FREQ_HZ * speedFactorA);
    }
  }
}
