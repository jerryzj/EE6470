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
using namespace sc_dt;
using namespace sc_core;
using sint = sc_int<32>;


const int MASK_X = 3;
const int MASK_Y = 3;
const int MASK_SIZE = MASK_X * MASK_Y;

SC_MODULE(Testbench){
public:
    // Read bmp outputs
    sc_fifo_out<int*> o_red;
    sc_fifo_out<int*> o_green;
    sc_fifo_out<int*> o_blue;
    // Write bmp inputs
    sc_fifo_in<int>  i_x;
    sc_fifo_in<int>  i_y;
    sc_fifo_in<int> i_red;
    sc_fifo_in<int> i_green;
    sc_fifo_in<int> i_blue;

    sc_event *o_read_finish;
    sc_event *i_median_finish;

    SC_CTOR(Testbench) {
        filter_r[MASK_SIZE] = {0};
        filter_g[MASK_SIZE] = {0};
        filter_b[MASK_SIZE] = {0};
        x = 0;
        y = 0;
        temp_r = 0;
        temp_g = 0;
        temp_b = 0;
        width = 0;
        height = 0;
        rgb_raw_data_offset = 0;
        bit_per_pixel = 0;
        byte_per_pixel = 0;
        image_s = NULL;
        image_t = NULL;
        SC_THREAD(write_bmp);
        SC_THREAD(read_bmp);
    }
private:
    // read bmp
    int filter_r[MASK_SIZE];
    int filter_g[MASK_SIZE];
    int filter_b[MASK_SIZE];
    // write bmp
    int x, y;
    int temp_r,temp_g,temp_b;
    // shared variables
    unsigned int   width;
    unsigned int   height;
    unsigned int   rgb_raw_data_offset;
    unsigned char  bit_per_pixel;
    unsigned short byte_per_pixel;
    unsigned char  *image_s;     // source image array
    unsigned char  *image_t;     // target image array
    unsigned char header[54] = {
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
    void read_bmp();
    void write_bmp();
};

SC_MODULE(Median){
public:
    // Inputs
    sc_fifo_in<int*> i_red;
    sc_fifo_in<int*> i_green;
    sc_fifo_in<int*> i_blue;
    // Outputs
    sc_fifo_out<int> o_red;
    sc_fifo_out<int> o_green;
    sc_fifo_out<int> o_blue;

    SC_CTOR(Median) {
        red_ptr = NULL;
        green_ptr = NULL;
        blue_ptr = NULL;
        red[MASK_SIZE] = {0};
        green[MASK_SIZE] = {0};
        blue[MASK_SIZE] = {0};
        SC_THREAD(do_median);
    }
private:
    int* red_ptr;
    int* green_ptr;
    int* blue_ptr;
    int red[MASK_SIZE];
    int green[MASK_SIZE];
    int blue[MASK_SIZE];
    void do_median();
};
#endif