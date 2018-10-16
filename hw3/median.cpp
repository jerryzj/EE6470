#include "median.hpp"

Median::Median(sc_module_name n) : sc_module(n), t_skt("t_skt"), base_offset(0) {
    red[MASK_SIZE] = {0};
    green[MASK_SIZE] = {0};
    blue[MASK_SIZE] = {0};
    old_r[MASK_SIZE] = {0};
    old_g[MASK_SIZE] = {0};
    old_b[MASK_SIZE] = {0};
    SC_THREAD(do_median);
    t_skt.register_b_transport(this, &Median::blocking_transport);
}

void Median::do_median(){
    for(unsigned int y = 0;  y < height; y++){
        for(unsigned int x = 0; x < width; x++){
            if(x == 0){ // Update the whole filter
                for(int j = 0; j < MASK_Y; j++){
                    for(int i = 0; i < MASK_X; i++){
                        old_r[j * MASK_X + i] = i_red.read();
                        old_g[j * MASK_X + i] = i_green.read();
                        old_b[j * MASK_X + i] = i_blue.read();
                    }
                }
            }
            else{       // Update row only
                for(int j = 0; j < MASK_Y; j++){
                    for(int i = 0; i < MASK_X - 1; i++){
                        old_r[j * MASK_X + i] = old_r[j * MASK_X + (i+1)];
                        old_g[j * MASK_X + i] = old_g[j * MASK_X + (i+1)];
                        old_b[j * MASK_X + i] = old_b[j * MASK_X + (i+1)];
                    }
                    old_r[j * MASK_X + MASK_X-1] = i_red.read();
                    old_g[j * MASK_X + MASK_X-1] = i_green.read();
                    old_b[j * MASK_X + MASK_X-1] = i_blue.read();
                }
            }
            for(int i = 0; i < MASK_SIZE; i++){ // restore 
                red[i] = old_r[i];
                green[i] = old_g[i];
                blue[i] = old_b[i];
            }
            int k = MASK_SIZE / 2;
            sort(red, red + MASK_SIZE);
            sort(green, green + MASK_SIZE);
            sort(blue, blue + MASK_SIZE);
            o_red.write(red[k]);
            o_green.write(green[k]);
            o_blue.write(blue[k]);
        }
    }
}

void Median::blocking_transport(tlm::tlm_generic_payload &payload, sc_core::sc_time &delay) {
    sc_dt::uint64 addr = payload.get_address();
    addr = addr - base_offset;
    unsigned char *mask_ptr = payload.get_byte_enable_ptr();
    unsigned char *data_ptr = payload.get_data_ptr();
    word buffer;
    switch(payload.get_command()){
        case tlm::TLM_READ_COMMAND:
            switch(addr){
                case MEDIAN_FILTER_RESULT_ADDR: 
                    buffer.uc[0] = i_red.read();
                    buffer.uc[1] = i_green.read();
                    buffer.uc[2] = i_blue.read();
                break;
                default:
                    cerr<<"Error! Medium::blocking_transport: address 0x"
                        <<std::setfill('0')<<std::setw(8)<<std::hex<<addr<<std::dec
                        <<" is not valid"<<std::endl;
                break;
            }
            data_ptr[0] = buffer.uc[0];
            data_ptr[1] = buffer.uc[1];
            data_ptr[2] = buffer.uc[2];
        break;
        case tlm::TLM_WRITE_COMMAND:
            switch(addr){
                case MEDIAN_FILTER_R_ADDR: 
                    if (mask_ptr[0] == 0xff){
                        o_red.write(data_ptr[0]);
                    }
                    if (mask_ptr[1] == 0xff ) {
                        o_green.write(data_ptr[1]);
                    }
                    if (mask_ptr[2] == 0xff ) {
                        o_blue.write(data_ptr[2]);
                    }
                break;
                default:
                cerr<<"Error! Medium::blocking_transport: address 0x"
                    <<std::setfill('0')<<std::setw(8)<<std::hex<<addr<<std::dec
                    <<" is not valid"<<std::endl;
                break;
            }
        break;
        case tlm::TLM_IGNORE_COMMAND:
            payload.set_response_status(tlm::TLM_GENERIC_ERROR_RESPONSE);
            return;
        default:
            payload.set_response_status(tlm::TLM_GENERIC_ERROR_RESPONSE);
            return;
    }
    payload.set_response_status(tlm::TLM_OK_RESPONSE);  // Always OK
}

void Median::set_h_w(unsigned int h, unsigned int w){
    height = h;
    width = w;
}