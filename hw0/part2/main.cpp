#include "median.hpp"

using namespace std;

// TIMEVAL STRUCT IS Defined ctime
// use start_time and end_time variables to capture
// start of simulation and end of simulation
struct timeval start_time, end_time;

int sc_main(){
    Medianfilter median("median");
    
    sc_start();
    cout<<"Simulated time == "<< sc_core::sc_time_stamp()<<endl;
    
    return 0;
}
