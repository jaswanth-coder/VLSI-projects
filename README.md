# VLSI Projects

This repository contains various VLSI-based hardware design implementations, including Verilog codes and Xilinx HLS programs. These projects cover fundamental digital design concepts such as scheduling, memory design, and digital filters.

## Contents

### 1. Round Robin Scheduling (Verilog)
- Implements a **Round Robin Scheduler** in Verilog.
- Useful for **task scheduling** in hardware-based systems.
- Ensures fair allocation of resources among multiple processes.

### 2. Single Port ROM (Verilog)
- Read-only memory (ROM) implementation with a single read port.
- Useful for lookup tables, firmware storage, and embedded applications.

### 3. Dual Port ROM (Verilog)
- ROM with two read ports, allowing concurrent read operations.
- Enhances performance in **high-speed** digital applications.

### 4. RAM (Verilog)
- Implementation of a Random Access Memory (RAM) module.
- Supports both read and write operations.
- Essential for **storage and buffer management** in digital circuits.

### 5. Xilinx HLS: 11-Tap FIR Filter
- Implementation of an **11-tap Finite Impulse Response (FIR) filter** using **Xilinx High-Level Synthesis (HLS)**.
- Includes **C-based design**, **synthesis results**, and performance analysis.
- Optimized for FPGA-based digital signal processing (DSP) applications.

## Getting Started

### Prerequisites
- **Verilog Development**
  - Xilinx Vivado / ModelSim for simulation and synthesis
  - Any Verilog-compatible simulator
- **Xilinx HLS Development**
  - Xilinx Vitis HLS for compiling and analyzing the FIR filter

### Running the Verilog Code
1. Clone the repository:
   ```bash
   git clone https://github.com/jaswanth-coder/VLSI-projects.git
   cd VLSI-projects
   ```
2. Open the Verilog files in **Vivado/ModelSim**.
3. Run the simulation and analyze waveforms.
4. Synthesize and implement the design on an FPGA if needed.

### Running the FIR Filter in Xilinx HLS
1. Open **Xilinx Vitis HLS**.
2. Import the **FIR filter source code**.
3. Run **C simulation** to verify the results.
4. Perform **Synthesis & Co-Simulation** to analyze FPGA performance.

## Results
- The repository contains testbench files and simulation results for verification.
- The **FIR filter HLS report** includes latency, area utilization, and performance metrics.

## Contributing
Contributions are welcome! Feel free to open an issue or submit a pull request.

## License
This project is licensed under the **MIT License**.

---
For any queries, reach out to **[Jaswanth Kumar](https://github.com/jaswanth-coder)**.
