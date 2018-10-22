# EE6470 HW4 Median Filter

#### 107061517 張簡崇堯
## Execution
```
$ make // compile
$ make run // execution, output file will be lena_filtered.bmp
```
## Introduction
In this homework, I implemented the median filter through C++ and SystemC with TLM bus interface. The median filter is a digital filtering technique, which often used to remove noise from an image or signal.
## Implementation
In this homework, I just add TLM bus module and do some linking based on the previous homework.
## Results
### Before
![Imgur](https://i.imgur.com/tu9o14M.png)
### After
![Imgur](https://i.imgur.com/P76HgHK.png)
### Number of pixels transmitted
In the old model, the total transmitted pixels are 2359296, and the optimized model only transmits 789504 pixels. The pixels transmitted ratio between the two models is 2.98.