#include <Arduino.h>

// --- Pins TB6612FNG Motor A (Stundenzeiger) ---
#define AIN1 4
#define AIN2 5
#define PWMA 6

// --- Pins TB6612FNG Motor B (Minutenzeiger) ---
#define BIN1 7
#define BIN2 8
#define PWMB 9

#define STBY 3

// --- Geschwindigkeitskonstanten (0–255) ---
// Beide Werte unabhängig voneinander einstellbar → unterschiedliche Zeigergeschwindigkeiten
float SPEED_FACTOR_A = 0.3f;  // Stundenzeiger (langsamer)
float SPEED_FACTOR_B = 0.6f;  // Minutenzeiger (schneller)

uint8_t pwmA() { return (uint8_t)(255 * SPEED_FACTOR_A); }
uint8_t pwmB() { return (uint8_t)(255 * SPEED_FACTOR_B); }

void motorForward(uint8_t in1, uint8_t in2, uint8_t pwmPin, uint8_t speed) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(pwmPin, speed);
}

void setup() {
    pinMode(AIN1, OUTPUT); pinMode(AIN2, OUTPUT); pinMode(PWMA, OUTPUT);
    pinMode(BIN1, OUTPUT); pinMode(BIN2, OUTPUT); pinMode(PWMB, OUTPUT);
    pinMode(STBY, OUTPUT);
    digitalWrite(STBY, HIGH);

    Serial.begin(9600);
}

void loop() {
    // Geschwindigkeit optional per Serial anpassen: "A0.4" setzt SPEED_FACTOR_A auf 0.4
    if (Serial.available()) {
        char motor = Serial.read();
        float val = Serial.parseFloat();
        if (motor == 'A') SPEED_FACTOR_A = constrain(val, 0.0f, 1.0f);
        if (motor == 'B') SPEED_FACTOR_B = constrain(val, 0.0f, 1.0f);
    }

    motorForward(AIN1, AIN2, PWMA, pwmA());
    motorForward(BIN1, BIN2, PWMB, pwmB());
}
