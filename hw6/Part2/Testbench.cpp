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
    wait(10);

    for(int i = 0; i < o_ch; ++i){
        for(int j = 0; j < o_width; ++j){
            for(int k = 0; k < o_height; ++k){
                result = 0;
#ifndef NATIVE_SYSTEMC
                result = input.get();
#else
                result = input.read();
#endif
                cout<<result<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        _pooling_done.notify();
    }
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
    
    for(int i = 0; i < i_ch; ++i){
        cout<<"Input data channel: "<<i<<endl;
        for(int j = 0; j < i_width; ++j){
            for(int k = 0; k < i_height ; ++k){
                data = rand() % 256;
                cout<<data<<" ";
#ifndef NATIVE_SYSTEMC
                output.put(data);
#else
                output.write(data);
#endif
                data = 0;
            }
            cout<<endl;
        }
        cout<<endl;
        wait(_pooling_done);
    }
}
