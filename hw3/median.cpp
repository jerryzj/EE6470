#include "median.hpp"

Median::Median(sc_module_name n) : sc_module(n), t_skt("t_skt"), base_offset(0) {
    red[MASK_SIZE] = {0};
    green[MASK_SIZE] = {0};
    blue[MASK_SIZE] = {0};
    sort_r[MASK_SIZE] = {0};
    sort_g[MASK_SIZE] = {0};
    sort_b[MASK_SIZE] = {0};
    old_r[MASK_SIZE] = {0};
    old_g[MASK_SIZE] = {0};
    old_b[MASK_SIZE] = {0};
    SC_THREAD(do_median);
    t_skt.register_b_transport(this, &Median::blocking_transport);
}

void Median::do_median(){
    
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
                    buffer.result[0] = i_red.read();
                    buffer.result[1] = i_green.read();
                    buffer.result[2] = i_blue.read();
                break;
                default:
                    cerr<<"Error! Medium::blocking_transport: address 0x"
                        <<std::setfill('0')<<std::setw(8)<<std::hex<<addr<<std::dec
                        <<" is not valid"<<std::endl;
                break;
            }
            data_ptr[0] = buffer.result[0];
            data_ptr[1] = buffer.result[1];
            data_ptr[2] = buffer.result[2];
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