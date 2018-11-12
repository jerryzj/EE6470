#ifndef FILTER_DEF_H_
#define FILTER_DEF_H_


const unsigned int i_ch = 8;
const unsigned int i_width = 4;
const unsigned int i_height = 4;
const unsigned int window_w = 2;
const unsigned int window_h = 2;
const unsigned int stride = 2;
const unsigned int o_ch = i_ch;
const unsigned int o_width = i_width / stride;
const unsigned int o_height = i_height / stride;

#endif
