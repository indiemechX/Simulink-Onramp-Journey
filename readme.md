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
- `sketch.ino` — STM32 closed-loop PID controller and virtual first-order motor model

- `diagram.json` — Wokwi hardware connections
<img width="648" height="553" alt="hardware" src="https://github.com/user-attachments/assets/8279838e-76a0-4644-8a27-6abff0997c5e" />

- — Case 1 recordings
-  — Case 2 recordings
