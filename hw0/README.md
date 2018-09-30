# EE6470 HW1 Median Filter

#### 107061517 張簡崇堯
## Execution
```
$ make // compile
$ make run // execution, output file will be lena_filtered.bmp
```
## Introduction
In this homework, I implemented the median filter through C++ and systemC. The median filter is a digital filtering technique, which often used to remove noise from an image or signal.
## Implementation
* Part I
The source code is mainly from the introduction website and TA's sobel filter example.
The example code of finding median value is too complex, I use STL sort instead.
* Part II
  * Three **SC_METHOD**: read_bmp, do_median, and write_bmp.
  * Event-based model to ensure data correctness.
    1. _read_finish: When the data of a mask is ready, read_bmp will send a notify signal, and wait for _median_ready event.
    2. _median_finish: When the median value of R,G, and B three layers is generated, do_median will send a notify  signal and wait for _write_finish event and wait for _write_finish event. 			
    3. _median_ready: When _write_finish event is happen, do_median will send a notify signal to inform read_bmp.
    4. _write_finish: When the median value of R, G, and B three median values are written into output file pointer and the image is not completely filtered.
## Results
### Before
[Imgur](https://i.imgur.com/tu9o14M.png)
### After
[Imgur](https://i.imgur.com/P76HgHK.png)
## Discussion
Some error will happen when -O3 flag is set on EE workstation(g++ 7.3.0). But use Apple LLVM 10.0.0 works well. 
