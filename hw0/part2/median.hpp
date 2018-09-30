#ifndef MEDIAN_HPP
#define MEDIAN_HPP

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <sys/time.h>
using namespace std;

#include <systemc>
using namespace sc_core;

const int WHITE = 255;
const int BLACK = 0;
const int MASK_X = 3;
const int MASK_Y = 3;

class Medianfilter: public sc_module{
public:
    SC_HAS_PROCESS(Medianfilter);
    Medianfilter(sc_module_name n);
    ~Medianfilter();
    void read_bmp(const char *fname_s);
    void write_bmp(const char *fname_t);
private:
    // Functions
    void do_median();                       // median filter call
    int median(int* data, int end, int k);  // find median number(not index)
    // Variables
    int temp_r;
    int temp_g;
    int temp_b;
    int x, y;                   // index being shared between read_bmp & do_median
    unsigned char *image_s;     // source image array
    unsigned char *image_t;     // target image array
    unsigned int   width, height;      // image width, image height
    unsigned int   rgb_raw_data_offset;// RGB raw data offset
    unsigned char  bit_per_pixel;      // bit per pixel
    unsigned short byte_per_pixel;     // byte per pixel
    unsigned char header[54] = {       // BMP file header
        0x42,        // identity : B
        0x4d,        // identity : M
        0, 0, 0, 0,  // file size
        0, 0,        // reserved1
        0, 0,        // reserved2
        54, 0, 0, 0, // RGB data offset
        40, 0, 0, 0, // struct BITMAPINFOHEADER size
        0, 0, 0, 0,  // bmp width
        0, 0, 0, 0,  // bmp height
        1, 0,        // planes
        24, 0,       // bit per pixel
        0, 0, 0, 0,  // compression
        0, 0, 0, 0,  // data size
        0, 0, 0, 0,  // h resolution
        0, 0, 0, 0,  // v resolution
        0, 0, 0, 0,  // used colors
        0, 0, 0, 0   // important colors
    };
    // Color arrays
    int red[MASK_X * MASK_Y];
    int green[MASK_X * MASK_Y];
    int blue[MASK_X * MASK_Y];
    // SystemC events
    sc_event _read_finish;      // When a mask of data is read from image_s
    sc_event _median_finish;    // When median calculation is done
    sc_event _median_ready;     // When do_median & write_bmp finish
    sc_event _write_finish;     // When a pixel is written to image_t
};
#endif