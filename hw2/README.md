# EE6470 HW2 Median Filter

#### 107061517 張簡崇堯
## Execution
```
$ make // compile
$ make run // execution, output file will be lena_filtered.bmp
```
## Introduction
In this homework, I implemented the median filter through C++ and SystemC with FIFO. The median filter is a digital filtering technique, which often used to remove noise from an image or signal.
## Implementation
* Part I
  * Two modules: Testbench and Median
  * The source code is mainly from the previous homework. But I do some rearrangement job and use sc_fifo instead of sc_event to transmit filter data between testbench and median modules.
  * FIFO-based model (use pointer to pass filter infomation)to ensure data correctness.
* Part II
  * I do some optimized work on the filter data transmission. The main idea is build a buffer to keep the repeated pixel. Therefore, the transmmited data can be reduced to 1/3 compare to the original design.
  
## Results
### Before
![Imgur](https://i.imgur.com/tu9o14M.png)
### After
![Imgur](https://i.imgur.com/P76HgHK.png)
### Number of pixels tranmitted
* In old model, the total transmitted pixels are 2359296, and the optimized model only transmits 789333 pixels. The pixels transmitted ratio between the two model is 2.98.
## Discussion
* Becareful when you use **wait** command.