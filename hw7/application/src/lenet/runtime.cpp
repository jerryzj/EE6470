#include <cstdlib>
#include <cassert>
#include <fstream>
#include <iostream>
#include "runtime.h"

void* TVMBackendAllocWorkspace(int device_type,
                                       int device_id,
                                       uint32_t nbytes,
                                       int dtype_code_hint,
                                       int dtype_bits_hint) {
  void* ret = std::malloc(nbytes);
  return ret;
}

int TVMBackendFreeWorkspace(int device_type,
                            int device_id,
                            void* ptr) {
  std::free(ptr);
  return 0;
}

template <class T>
void compare(T* golden_out,T* ret, int num) {
    const double hard_error_limit = error_limit;
    int error_num = 0;
    for(int i=0;i<num;++i) {
        const double a = static_cast<double>(golden_out[i]);
        const double b = static_cast<double>(ret[i]);
        const double error = a-b;
        const double error_ratio = error / a;
        const bool ratio_exceed = error_ratio > ratio_limit;
        const bool error_exceed = error > error_limit;
        const bool hard_error_exceed = error > hard_error_limit;
        if (error == 0) continue;
        else if (ratio_exceed & error_exceed) {
            ++error_num;
            std::cout << "index:"<< i << "," << a << "," << b << std::endl;
            assert(!hard_error_exceed && "hard error exceed");
        }
    }
    if (error_num > 0) {
        std::cout << "Total " << error_num << " errors exceed " << error_limit << "\n";
    } else {
        std::cout << "The network finishes correctly!\n";
    }
}

template <class T>
void dump(T* golden_out,T* ret, int num) {
    std::ofstream of1("error");
    std::ofstream of2("ratio");
    for(int i=0;i<num;++i) {
        const double a = static_cast<double>(golden_out[i]);
        const double b = static_cast<double>(ret[i]);
        const double error = a-b;
        const double error_ratio = error / a;
        of1 << error << ",";
        of2 << error_ratio << ",";
    }
}

// template instantiation for float type
template void dump<float>(float* golden_out,float* ret, int num);
template void compare<float>(float* golden_out,float* ret, int num);

// template instantiation for double type
template void dump<double>(double* golden_out,double* ret, int num);
template void compare<double>(double* golden_out,double* ret, int num);
