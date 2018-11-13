

# EE6470 HW5 Pooling Engine using HLS

#### 107061517 張簡崇堯
## Execution
```shell
# Assume you are already in project root dir (stratus)
$ make sim_V_BASIC
```
## Introduction

In this homework, I implement a pooling engine and use Stratus HLS tool to generate correspoding RTL code, then use  ncsim to test if my design works well.

To compare the affect of decompse image, I modify my design and reduce the size of engine input. The result shows that the area is 90% reduced while the runtime remains the same (since the design is not pipelined) .

## Implementation

### Part I

The input size is set to 8 * 4 * 4 with stride = 2. There is a buffer in pooling engine that stores the whole input data, and a smaller window buffer with size is the square of stride.

### Part II

The input size is reduced to 1 * 4 * 4 with stride = 2. There is a buffer in pooling engine that stores the whole input data, and a smaller window buffer with size is the square of stride. The testbench needs to wait until the pooling engine sends results back each time.

## Results

### Execution results (only shows one channel)

```shell
Input data channel: 0
55 34 146 14 
59 21 133 28 
33 132 93 196 
39 159 218 36 

59 146 
159 218 
```

### Part I

#### Area

| Seq     | Comb  | Overall  |
| ------- | ----- | -------- |
| 23523.1 | 80831 | 104356.4 |

#### Time

5440 ns

### Part II

#### Area

| Seq    | Comb   | Overall |
| ------ | ------ | ------- |
| 3440.9 | 9884.7 | 13327.6 |

#### Time

5440 ns

## Conclusion & Discussion

Since my implementations are not pipelined and I didn't add any extra delay when moving data (I think the memory hierachy may affect the I/O delay), the runtime is the same between the two. However, the design area is significantly reduced to one tenth. I think this improvement mainly comes from the buffer size and correspoding MUXes.
