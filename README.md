<img width="1600" height="751" alt="github1" src="https://github.com/user-attachments/assets/0a379f62-4e15-4ab9-a252-f5ad3d1c899d" />
# Simulink Onramp Journey
Documentation of my transition from ECE theory to Model-Based Design. 

## 🚀 Featured Project: Falling Object Velocity Model
This model simulates a falling object subject to gravity and non-linear drag forces.

### 🔍 The "Ghost Connection" Debug
During the simulation, I encountered a logical discrepancy where the graph output showed an initial offset (starting at -7) despite the **Integrator Block's** initial condition being correctly set to 0. 

After verifying the internal parameters, I identified this as a **Platform Synchronization issue**. 

