<img width="1600" height="751" alt="github1" src="https://github.com/user-attachments/assets/0a379f62-4e15-4ab9-a252-f5ad3d1c899d" />
# Simulink Onramp Journey
Documentation of my transition from ECE theory to Model-Based Design. 

## 🚀 Featured Project: Falling Object Velocity Model
This model simulates a falling object subject to gravity and non-linear drag forces.

### 🔍 The "Ghost Connection" Debug
During the simulation, I encountered a logical discrepancy where the graph output showed an initial offset (starting at -7) despite the **Integrator Block's** initial condition being correctly set to 0. 

After verifying the internal parameters, I identified this as a **Platform Synchronization issue**. 


## 🛠️ Module 2: Mathematical Operators & Signal Routing
*Date:* April 26, 2026
*Environment:* Simulink Online / MATLAB Academy
*Hardware Notes:* Managed session during thermal throttling; utilized search shortcuts to optimize performance.


### 🟢 Task 1: Non-Linear Transformation (Square Root)
* *Objective:* Compute the square root of a time-varying ramp signal (u(t) = 2t).
* *Conceptual Insight:* Real-world physical systems (like fluid flow through an orifice) often follow non-linear square-root laws. This task models that transformation.
* *Implementation:* Integrated the Sqrt block from the Math Operations library.

<img width="1329" height="626" alt="task2" src="https://github.com/user-attachments/assets/e583221f-5d6e-4dc8-be3a-d71e79cde733" />

### 🟢 Task 2 & 3: Constant Sources and Signal Referencing
* *Objective:* Implement a static reference signal (Setpoint) and verify signal flow.
* *Conceptual Insight:* In Control Systems, the *Constant Block* represents the "Desired State" or "Setpoint" (R(s)). Establishing a steady reference is the first step in building a closed-loop controller.
* *Implementation:* - Added a Constant block with a value of 3.
  - Routed signals to multiple Signal Assessment blocks for simultaneous verification.
-
<img width="302" height="202" alt="task3" src="https://github.com/user-attachments/assets/cc1e7c5b-9424-47a3-9ce9-fb5f93038bc4" />
<img width="295" height="289" alt="task3a" src="https://github.com/user-attachments/assets/e342a952-d633-47d5-88f5-d023ba64caf9" />
---
## 🧠 Module 3: Decision Logic & Threshold Detection
**Date:** April 27, 2026  
**Environment:** Simulink Online / MATLAB Academy  
**Hardware Notes:** Successfully navigated a UI freeze (System Resilience Level: Expert) while monitoring thermal limits at 35°C.

### 🟢 Task 4: Strict Relational Mapping
* **Objective:** Implement a zero-crossing detector to convert a continuous Sine Wave into a binary logical state (1 or 0).
* **Conceptual Insight:** In Control Systems, precision at the boundary is everything. Moving from a non-strict `>=` to a strict `>` operator ensures the system only triggers when the signal is definitively positive—essential for timing in Power Electronics and safety interlocks.
* **Implementation:** Integrated the `Compare To Zero` block and verified strictly greater-than logic through the Signal Assessment suite.

![Boolean Logic Success]
<img width="1303" height="447" alt="task4boollogic" src="https://github.com/user-attachments/assets/7be58687-7f36-4abd-8bdc-8ab41574d9fa" />

---
### 🏎️ The "Gold" Connection: F1 & Industry
This logic mirrors the **DRS Activation** protocols used in Formula 1 (where a sub-millisecond boundary determines performance) and the **Force Feedback** safety loops in Japanese industrial robotics. Establishing these "logical eyes" is the first step toward building autonomous behavior.
