# Phase 2: Closed-Loop PID Control on STM32 Nucleo-C031C6 (Wokwi)

A closed-loop PID motor speed control simulation on **STM32 Nucleo-C031C6** using **Wokwi**. A potentiometer provides the live target setpoint, a first-order plant model simulates motor dynamics, and real-time telemetry is visualized via Serial Monitor and Serial Plotter.

## System Overview
- **Microcontroller / Simulator:** STM32 Nucleo-C031C6 (Wokwi)
- **Control Loop Rate:** 50 Hz (`dt = 0.02 s`)
- **Plant Model:** First-order virtual motor with time constant $\tau = 0.25\text{ s}$
- **Anti-Windup:** Integral term clamped to `[-50.0, 50.0]`
- **Control Output Saturation:** Clamped to `[0.0, 100.0]` and mapped to PWM (`0–255`)

## Pin Connections
| Potentiometer Wiper | `A0` | Analog setpoint (`0–100%`) |
| Potentiometer `VCC` | `3V3` | Reference supply |
| Potentiometer `GND` | `GND` | Common ground |
| PWM Control Output | `PWM / D9` | Duty cycle driven by PID output |

## PID Tuning Cases

 Parameters --> kp, ki, kd :- Case 1: Baseline and  Case 2: Tuned 
| **Kp** | 1) `1.8` | 2) `4.5` |
| **Ki** | 1) 0.8` | 2)`2.0` |
| **Kd** | 1) `0.05` | 2) `0.02` |
| **Behavior** | 1) Slower initial ramp | 2) Faster rise time, locks cleanly to setpoint |

## Simulation Demonstrations

### Case 1: Baseline Tuning (K_p = 1.8, K_i = 0.8, K_d = 0.05)
- **Numeric Telemetry (`Setpoint`, `Speed`, `PWM`):**


### Case 2: Tuned Parameters ($K_p = 4.5, K_i = 2.0, K_d = 0.02$)
- **Numeric Telemetry (`Setpoint`, `Speed`, `PWM`):**

  Case 2 Numeric Telemetry

- **Step Response Plot:**

  Case 2 Step Response Plot

## Key Takeaways
- Changing the potentiometer at `A0` dynamically updates `Setpoint`, driving `Speed` toward the target through the closed-loop PID controller.
- Increasing K_p and K_i in Case 2 speeds up the response and eliminates steady-state error so `Speed` converges to `Setpoint`.

## Files in This Phase
- [`sketch.ino`](sketch.ino) — STM32 closed-loop PID controller and virtual first-order motor model

- [`diagram.json`](diagram.json) — Wokwi hardware connections

- — Case 1 recordings
- <img width="640" height="360" alt="case1(telemetry)" src="https://github.com/user-attachments/assets/8d7236c4-bf4d-4301-9375-d27f169d8e2d" />
<img width="640" height="360" alt="case1(step_response)" src="https://github.com/user-attachments/assets/bc43806a-c2d4-48ed-9dd7-f1fa23188158" />


-  — Case 2 recordings
<img width="360" height="640" alt="case2(telemetry)" src="https://github.com/user-attachments/assets/cd5e5ab9-4bed-4e8a-b7dc-0d01ab532c22" />
<img width="478" height="850" alt="case2--step_response-ezgif com-optimize (1)" src="https://github.com/user-attachments/assets/c8ab9655-1dc0-4b79-94e5-24c6e93ffef7" />




