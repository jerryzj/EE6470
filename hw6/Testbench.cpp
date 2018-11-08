#include "Testbench.h"

Testbench::Testbench(sc_module_name n) : sc_module(n){
    result = 0;
    SC_THREAD(GenTestData);
    sensitive << i_clk.pos();
    dont_initialize();
    SC_THREAD(fetch_result);
    sensitive << i_clk.pos();
    dont_initialize();
}

Testbench::~Testbench() {
    cout << "Total run time = " << total_run_time << endl;
}

void Testbench::fetch_result(){
#ifndef NATIVE_SYSTEMC
    input.reset();
#endif
    wait(5);
    //wait(1);
#ifndef NATIVE_SYSTEMC
    result = input.get();
#else
    result = input.read();
#endif
    total_run_time = sc_time_stamp() - total_start_time;
    sc_stop();
}

void Testbench::GenTestData() {
    sc_uint<32> data;
    
    n_txn = 0;
    max_txn_time = SC_ZERO_TIME;
    min_txn_time = SC_ZERO_TIME;
    total_txn_time = SC_ZERO_TIME;

#ifndef NATIVE_SYSTEMC
    output.reset();
#endif
    o_rst.write(false);
    wait(5);
    o_rst.write(true);
    wait(1);
    total_start_time = sc_time_stamp();

    cout<<"Start generating test data"<<endl;
    for(int i = 0; i < i_ch; ++i){
        for(int j = 0; j < i_width; ++j){
            for(int k = 0; k < i_height ; ++k){
                data = rand() % 256;
#ifndef NATIVE_SYSTEMC
                output.put(rgb);
#else
                output.write(rgb);
#endif
            }
        }
    }
}
