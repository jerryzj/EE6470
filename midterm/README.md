# EE6470 Midterm Project

#### 107061517 張簡崇堯

## Introduction

In this project, I ported the MobileNet onto the SCML platform and use HLS tool to implement a convolution engine. Then use the timing from RTL simulation to estimate the runtime of MobileNet.

## Implementation

By analyzing the convolution layers in MobileNet, I noticed that the size of most input feature of convolution layer is smaller than 17 by 17. In this sense, the convolution operation can be divided into two groups in hardware processing. If the size is larger than 17, we need to split the input feature into many pieces. On the other hand, if the size is smaller than 17, we simply need to padding zeros on input feature.

I also decompose the 3D depth-wise convolution in MobileNet into 2D convolution. In hardware implementation, we need to add another input besides input feature, which is called input partial sum, which comes from the previous 2D convolution.

When implementing convolution engine with stride = 1, I noticed that my design will introduce RAW data hazard if I unrolled all the loops. Therefore, I can only unroll the inner loops which is used to go through the convolution kernel. And I also noticed that stride = 1 costs a lot of time and area, so I analyze the MobileNet again. 

I discovered that there are many convolution operations with stride = 1 and input feature size = 7 in the MobileNet, so I decide to implement another convolution with size = 7 to reduce runtime, and the simulation result shows that this approach can reduce 37% of runtime.

## Results

I use Stratus HLS tool and synthesize 5 different convolution engine.

![img](https://i.imgur.com/8uN9WAc.png)

The timing of the MobileNet on the SCML platform is 3.2s.





