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
* *Objective:* Compute the square root of a time-varying ramp signal ($u(t) = 2t$).
* *Conceptual Insight:* Real-world physical systems (like fluid flow through an orifice) often follow non-linear square-root laws. This task models that transformation.
* *Implementation:* Integrated the Sqrt block from the Math Operations library.

<img width="1329" height="626" alt="task2" src="https://github.com/user-attachments/assets/e583221f-5d6e-4dc8-be3a-d71e79cde733" />

### 🟢 Task 2 & 3: Constant Sources and Signal Referencing
* *Objective:* Implement a static reference signal (Setpoint) and verify signal flow.
* *Conceptual Insight:* In Control Systems, the *Constant Block* represents the "Desired State" or "Setpoint" ($R(s)$). Establishing a steady reference is the first step in building a closed-loop controller.
* *Implementation:* - Added a Constant block with a value of 3.
  - Routed signals to multiple Signal Assessment blocks for simultaneous verification.

<img width="302" height="202" alt="task3" src="https://github.com/user-attachments/assets/cc1e7c5b-9424-47a3-9ce9-fb5f93038bc4" />
<img width="295" height="289" alt="task3a" src="https://github.com/user-attachments/assets/e342a952-d633-47d5-88f5-d023ba64caf9" />

