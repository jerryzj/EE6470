# EE6470 HW3 Median Filter

#### 107061517 張簡崇堯
## Execution
```
$ make // compile
$ make run // execution, output file will be lena_filtered.bmp
```
## Introduction
In this homework, I implemented the median filter through C++ and SystemC with TLM interface. The median filter is a digital filtering technique, which often used to remove noise from an image or signal.
## Implementation
In the previous homework, I use a fine-grained approach to decide pixels to be transmitted, which means I only transmit the modified pixels only. However, this approach only reduces less than 0.02% pixels' transmission, but costs more memory and logical operation on each iteration.

Therefore, I use a coarse-grained approach to implement I/O handler. Instead of using complex comparison to check if a pixel is changed, I update all the pixels of a mask in the beginning of each row, and update a row for other cases.

## Results
### Before
![Imgur](https://i.imgur.com/tu9o14M.png)
### After
![Imgur](https://i.imgur.com/P76HgHK.png)
### Number of pixels transmitted
In the old model, the total transmitted pixels are 2359296, and the optimized model only transmits 789504 pixels. The pixels transmitted ratio between the two models is 2.98.
## Discussion
Why we need to use sc_fifo instead of sc_fifo_in/out on Median filter module? Otherwise, it will lead to socket binding error.