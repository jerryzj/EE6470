#ifndef FILTER_DEF_H_
#define FILTER_DEF_H_

// Input size
const unsigned int i_ch = 3;
const unsigned int i_width = 17;
const unsigned int i_height = 17;
// Output size
const unsigned int o_ch = 8;
const unsigned int o_width = 8;
const unsigned int o_height = 8;
// Kernel size
const unsigned int k_batch_size = 8;
const unsigned int k_ch = 3;
const unsigned int k_width = 3;
const unsigned int k_height = 3;
// Calculate stride using lambda function
const unsigned int stride = [](unsigned int in_shape_h, unsigned int out_shape_h){
    const float in_h = static_cast<float>(in_shape_h);
    const float out_h = static_cast<float>(out_shape_h);
    const float ratio = in_h / out_h;
    const unsigned int stride = static_cast<unsigned int>(std::round(ratio));
    return stride;
}(i_height - k_height, o_height);

#endif
