#pragma once
#include "c_runtime_api.h"
void conv2d(TVMValue stack_value, int arg_num);
void pool2d(TVMValue stack_value, int arg_num);
void norm2d(TVMValue stack_value, int arg_num);
void relu2d(TVMValue stack_value, int arg_num);
