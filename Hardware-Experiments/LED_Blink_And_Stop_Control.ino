/*
 * Project: Physical Hardware Foundation - LED Control
 * Experiment: 01 - Blink & Standby Sequence
 * Author: [Anjali/indiemechX]
 * * Description: 
 * This sketch controls an external LED on Pin 13. It alternates between 
 * an active "Blink" phase (System Running) and a "Standby" phase (System Idle).
 */

/*
 * Project: Physical Hardware Foundation - LED Control
 * Experiment: 01 - Blink & Standby Sequence
 * Author: [Anjali/indiemechX]
 * Description: 
 * This sketch controls an external LED on Pin 13. It alternates between 
 * an active "Blink" phase (System Running) and a "Standby" phase (System Idle).
 */

const int ledPin = 13; // Hardware Pin 13 (Standard Arduino LED Pin)

void setup() {
  // Initialize the digital pin as an output.
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // --- PHASE 1: ACTIVE BLINK (Simulating System Operation) ---
  // The LED will blink 10 times at a high frequency (200ms)
  for(int i = 0; i < 10; i++) {
    digitalWrite(ledPin, HIGH); // Turn LED ON
    delay(200);                 // Wait 0.2 sec
    digitalWrite(ledPin, LOW);  // Turn LED OFF
    delay(200);                 // Wait 0.2 sec
  }

  // --- PHASE 2: STANDBY (Simulating System Idle/Stop) ---
  // The LED stays OFF for 5 seconds to show the 'Stop' logic works.
  digitalWrite(ledPin, LOW);    
  delay(5000);                  // 5-second pause
}
