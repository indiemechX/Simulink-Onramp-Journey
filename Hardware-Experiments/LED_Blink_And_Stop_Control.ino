/*
 * Project: Physical Hardware Foundation - LED Control
 * Experiment: 01 - Blink & Standby Sequence
 * Author: [Anjali/indiemechX]
 * * Description: 
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
Welcome to my development log for a custom Arduino-based Casino Game. This project follows a strict *Modular Testing Protocol*—verifying individual hardware components (LEDs, Buzzers, Displays) before final system integration.

---

## 🏗️ Module 1: Physical Foundation (LED & Timing)
The first phase focused on establishing a stable "Heartbeat" for the system. I implemented a state-machine logic to alternate between active processing and low-power standby.

### 🎥 Hardware in Action
![LED Blink Sequence](Hardware-Experiments/led_blink_demo.gif)

### 🛠️ Technical Specifications
* *Controller:* Arduino Uno R3
* *Logic:* for loop iteration (10 cycles) @ 2.5Hz frequency.
* *Standby State:* 5000ms delay to simulate system idle/cooldown.
* *Hardware Setup:* External LED on Pin 13 using manual coil-wrap connectivity for a compact, breadboard-less prototype.
----

## 🔊 Next Milestone: Audio Feedback System
Currently developing *Module 2*, focusing on PWM-driven audio signals for real-time user feedback (Winning/Losing tones).
