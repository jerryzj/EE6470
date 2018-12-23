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

In this homework, I port Lenet to a RISC-V virtual platform and use pooling engine on the platform to finish the pooling computation.

## Results

### Execution results (only shows one channel)

```shell
The network finishes correctly!

Info: /OSCI/SystemC: Simulation stopped by user.
Info
Info ---------------------------------------------------
Info CPU 'cpu.RISC-V' STATISTICS
Info   Type                  : riscv (RV32I)
Info   Nominal MIPS          : 1000
Info   Final program counter : 0xaea14
Info   Simulated instructions: 44,815,463
Info   Simulated MIPS        : 2.1
Info ---------------------------------------------------
Info
Info ---------------------------------------------------
Info SIMULATION TIME STATISTICS
Info   Simulated time        : 0.04 seconds
Info   User time             : 21.21 seconds
Info   System time           : 0.01 seconds
Info   Elapsed time          : 21.22 seconds
Info ---------------------------------------------------
```

## Conclusion & Discussion

Data type is very important.