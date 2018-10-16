#ifndef MEDIAN_HPP
#define MEDIAN_HPP

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <sys/time.h>
#include <iomanip>
using namespace std;

#include <systemc>
using namespace sc_dt;
using namespace sc_core;
using sint = sc_int<32>;

#include "Initiator.hpp"

const int MASK_X = 3;
const int MASK_Y = 3;
const int MASK_SIZE = MASK_X * MASK_Y;
const int MEDIAN_FILTER_R_ADDR (0x00000000);
const int MEDIAN_FILTER_RESULT_ADDR (0x00000004);

union word{
    int sint;
    unsigned int uint;
    unsigned char uc[4];
};

SC_MODULE(Testbench){
public:
    Initiator initiator;
    void read_bmp();
    void write_bmp();
    int get_width();
    int get_height();
    Testbench(sc_module_name n);
    ~Testbench();
    SC_HAS_PROCESS(Testbench);
private:
    // write bmp
    unsigned int x, y;
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
    void IO();
};

SC_MODULE(Median){
public:
    // Inputs
    sc_fifo_in<unsigned char> i_red;
    sc_fifo_in<unsigned char> i_green;
    sc_fifo_in<unsigned char> i_blue;
    sc_fifo_in<unsigned char> i_update_index;
    // Outputs
    sc_fifo_out<unsigned char> o_red;
    sc_fifo_out<unsigned char> o_green;
    sc_fifo_out<unsigned char> o_blue;
    tlm_utils::simple_target_socket<Median> t_skt;
    // Parameter setup
    void set_h_w(int h, int w);
    Median(sc_module_name n);
    ~Median();
private:
    unsigned char red[MASK_SIZE];
    unsigned char green[MASK_SIZE];
    unsigned char blue[MASK_SIZE];
    unsigned char old_r[MASK_SIZE];
    unsigned char old_g[MASK_SIZE];
    unsigned char old_b[MASK_SIZE];
    unsigned int base_offset;
    int width;
    int height;
    void do_median();
    void blocking_transport(tlm::tlm_generic_payload &payload, sc_core::sc_time &delay);
};
#endif