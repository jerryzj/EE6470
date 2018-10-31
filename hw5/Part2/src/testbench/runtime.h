#pragma once
#include <cstdint>
#include <cassert>
#include <iostream>
#include <fstream>

#include "c_runtime_api.h"
#include "OpUtil.h"
#include "Op.h"

#define CHECK(cond) if(!cond) std::cerr 
#define TVMFuncCall(func, val_array, arg_num) func(val_array, arg_num);

void* TVMBackendAllocWorkspace(int device_type,
                                       int device_id,
                                       uint64_t nbytes,
                                       int dtype_code_hint,
                                       int dtype_bits_hint);

int TVMBackendFreeWorkspace(int device_type,
                            int device_id,
                            void* ptr);

template <class T>
void dump(T* golden_out,T* ret, int num);
template <class T>
void compare(T* golden_out,T* ret, int num);
