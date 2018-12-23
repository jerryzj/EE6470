# EE6470 HW8 Multi-thread Pooling

#### 107061517 張簡崇堯

## Execution

```shell
# Build application and platform
$ ./test.sh
# Clean build dir
$ ./clean.sh
```

## Introduction

In this homework, I implement a multi-threaded pooling on existing Lenet.

## Results

### Execution results (only shows one channel)

```shell
The network finishes correctly!

Info: /OSCI/SystemC: Simulation stopped by user.
Info
Info ---------------------------------------------------
Info CPU 'multi_cpu_core.cpu_3.riscv_3' STATISTICS
Info   Type                  : riscv (RV32IMAC)
Info   Nominal MIPS          : 1000
Info   Final program counter : 0xaf1dc
Info   Simulated instructions: 65,000,126
Info   Simulated MIPS        : run too short for meaningful result
Info ---------------------------------------------------
Info
Info ---------------------------------------------------
Info CPU 'multi_cpu_core.cpu_2.riscv_2' STATISTICS
Info   Type                  : riscv (RV32IMAC)
Info   Nominal MIPS          : 1000
Info   Final program counter : 0xaf1dc
Info   Simulated instructions: 65,000,142
Info   Simulated MIPS        : run too short for meaningful result
Info ---------------------------------------------------
Info
Info ---------------------------------------------------
Info CPU 'multi_cpu_core.cpu_1.riscv_1' STATISTICS
Info   Type                  : riscv (RV32IMAC)
Info   Nominal MIPS          : 1000
Info   Final program counter : 0xaf1dc
Info   Simulated instructions: 65,000,135
Info   Simulated MIPS        : run too short for meaningful result
Info ---------------------------------------------------
Info
Info ---------------------------------------------------
Info CPU 'multi_cpu_core.cpu_0.riscv_0' STATISTICS
Info   Type                  : riscv (RV32IMAC)
Info   Nominal MIPS          : 1000
Info   Final program counter : 0xaf1dc
Info   Simulated instructions: 64,012,002
Info   Simulated MIPS        : run too short for meaningful result
Info ---------------------------------------------------
Info
Info ---------------------------------------------------
Info TOTAL
Info   Simulated instructions: 259,012,405
Info   Simulated MIPS        : run too short for meaningful result
Info ---------------------------------------------------
Info
Info ---------------------------------------------------
Info SIMULATION TIME STATISTICS
Info   Simulated time        : 0.06 seconds
Info   User time             : 0.45 seconds
Info   System time           : 0.00 seconds
Info   Elapsed time          : 0.46 seconds
Info ---------------------------------------------------
```

## Conclusion & Discussion

Data synchronization is very important.