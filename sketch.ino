// Phase 2: STM32 Nucleo C031C6 - Closed-Loop PID Motor Speed Control Simulation
const int POT_PIN = A0;     // Setpoint input (Potentiometer)
const int PWM_PIN = D9;     // PWM output to Motor / LED indicator

// PID Gains (Tunable parameters)
float Kp = 1.8;
float Ki = 0.8;
float Kd = 0.05;

// Control Loop & Virtual Plant Variables
float setpoint = 0.0;
float measuredSpeed = 0.0;  // Simulated motor speed (0 - 100%)
float integral = 0.0;
float prevError = 0.0;

unsigned long prevTime = 0;
const unsigned long sampleTimeMs = 20; // 50 Hz control loop (dt = 0.02s)

void setup() {
  Serial.begin(115200);
  pinMode(POT_PIN, INPUT);
  pinMode(PWM_PIN, OUTPUT);
  prevTime = millis();
}

void loop() {
  unsigned long currentTime = millis();
  if (currentTime - prevTime >= sampleTimeMs) {
    float dt = (currentTime - prevTime) / 1000.0;
    prevTime = currentTime;

    // 1. Read Potentiometer & map to Target Speed (0 to 100%)
    int rawAdc = analogRead(POT_PIN);
    setpoint = (rawAdc / 1023.0) * 100.0;

    // 2. PID Controller Computation
    float error = setpoint - measuredSpeed;
    integral += error * dt;
    integral = constrain(integral, -50.0, 50.0); // Anti-windup
    float derivative = (error - prevError) / dt;
    prevError = error;

    float controlOutput = (Kp * error) + (Ki * integral) + (Kd * derivative);
    controlOutput = constrain(controlOutput, 0.0, 100.0);

    // 3. Apply PWM Signal (0 - 255) to D9
    int pwmDuty = map((int)controlOutput, 0, 100, 0, 255);
    analogWrite(PWM_PIN, pwmDuty);

    // 4. First-Order Virtual DC Motor Plant (simulates mechanical inertia)
    // Tau = 0.25s time constant
    float tau = 0.25;
    measuredSpeed += (dt / tau) * (controlOutput - measuredSpeed);

    // 5. Serial Output for Monitoring / Serial Plotter
    Serial.print("Setpoint:");
    Serial.print(setpoint);
    Serial.print(",Speed:");
    Serial.print(measuredSpeed);
    Serial.print(",PWM:");
    Serial.println(controlOutput);
  }
}
