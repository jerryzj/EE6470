#include "Testbench.h"

Testbench::Testbench(sc_module_name n) : sc_module(n){
    result = 0;
    SC_THREAD(Test_Thread);
    sensitive << i_clk.pos();
    dont_initialize();

    SC_THREAD(fetch_result);
    sensitive << i_clk.pos();
    dont_initialize();
}

Testbench::~Testbench() {
    cout << "Total run time = " << total_run_time << endl;
}

Testbench::fetch_result(){
#ifndef NATIVE_SYSTEMC
    i_result.reset();
#endif
    wait(5);
    //wait(1);
#ifndef NATIVE_SYSTEMC
    result = i_result.get();
#else
    result = i_result.read();
#endif
    total_run_time = sc_time_stamp() - total_start_time;
    sc_stop();
}

void Testbench::Test_Thread(){

}

void Testbench::GenTestData() {
    sc_uint<32> data[4];
    
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

    for(uint i = 0; i < 4; i++){
        data[i] = rand() % 256;
#ifndef NATIVE_SYSTEMC
        output.put(data[i]);
#else
        output.write(data[i]);
#endif
    }
}
