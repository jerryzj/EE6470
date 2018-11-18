/*!
 *  Copyright (c) 2016 by Contributors
 * \file c_runtime_api.h
 * \brief TVM runtime library.
 *
 *  The philosophy of TVM project is to customize the compilation
 *  stage to generate code that can used by other projects transparently.
 *  So this is a minimum runtime code gluing, and some limited
 *  memory management code to enable quick testing.
 *
 *  The runtime API is independent from TVM compilation stack and can
 *  be linked via libtvm_runtime.
 *
 *  The common flow is:
 *   - Use TVMFuncListGlobalNames to get global function name
 *   - Use TVMFuncCall to call these functions.
 */
#ifndef TVM_RUNTIME_C_RUNTIME_API_H_
#define TVM_RUNTIME_C_RUNTIME_API_H_

// Macros to do weak linking
#ifdef _MSC_VER
#define TVM_WEAK __declspec(selectany)
#else
#define TVM_WEAK __attribute__((weak))
#endif

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#define TVM_DLL EMSCRIPTEN_KEEPALIVE
#endif

#ifndef TVM_DLL
#ifdef _WIN32
#ifdef TVM_EXPORTS
#define TVM_DLL __declspec(dllexport)
#else
#define TVM_DLL __declspec(dllimport)
#endif
#else
#define TVM_DLL
#endif
#endif

// TVM Runtime is DLPack compatible.
#include "dlpack.h"

#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
#include <stddef.h>

/*! \brief type of array index. */
typedef int64_t tvm_index_t;

/*! \brief Extension device types in TVM */
typedef enum {
  kDLVulkan = 7,
  kOpenGL = 11,
  // Extension DRAM type, used for quickly test extension device
  // The device api can differ depending on the xpu driver registered.
  kExtDev = 12,
  // AddExtraTVMType which is not in DLPack here
} TVMDeviceExtType;

/*!
 * \brief The type code in TVMType
 * \note TVMType is used in two places.
 */
typedef enum {
  // The type code of other types are compatible with DLPack.
  // The next few fields are extension types
  // that is used by TVM API calls.
  kHandle = 3U,
  kNull = 4U,
  kTVMType = 5U,
  kTVMContext = 6U,
  kArrayHandle = 7U,
  kNodeHandle = 8U,
  kModuleHandle = 9U,
  kFuncHandle = 10U,
  kStr = 11U,
  kBytes = 12U,
  // Extension codes for other frameworks to integrate TVM PackedFunc.
  // To make sure each framework's id do not conflict, use first and
  // last sections to mark ranges.
  // Open an issue at the repo if you need a section of code.
  kExtBegin = 15U,
  kNNVMFirst = 16U,
  kNNVMLast = 20U,
  // The following section of code is used for non-reserved types.
  kExtReserveEnd = 64U,
  kExtEnd = 128U
} TVMTypeCode;

/*!
 * \brief The data type used in TVM Runtime.
 *
 *  Examples
 *   - float: type_code = 2, bits = 32, lanes=1
 *   - float4(vectorized 4 float): type_code = 2, bits = 32, lanes=4
 *   - int8: type_code = 0, bits = 8, lanes=1
 *
 * \note Arguments TVM API function always takes bits=64 and lanes=1
 */
typedef DLDataType TVMType;

/*!
 * \brief The Device information, abstract away common device types.
 */
typedef DLContext TVMContext;

/*!
 * \brief The tensor array stucture to TVM API.
 */
typedef DLTensor TVMArray;

/*!
 * \brief Union type of values
 *  being passed through API and function calls.
 */
typedef union {
  int64_t v_int64;
  double v_float64;
  void* v_handle;
  const char* v_str;
  TVMType v_type;
  TVMContext v_ctx;
} TVMValue;

/*!
 * \brief Byte array type used to pass in byte array
 *  When kBytes is used as data type.
 */
typedef struct {
  const char* data;
  size_t size;
} TVMByteArray;

/*! \brief Handle to TVM runtime modules. */
typedef void* TVMModuleHandle;
/*! \brief Handle to packed function handle. */
typedef void* TVMFunctionHandle;
/*! \brief Handle to hold return value. */
typedef void* TVMRetValueHandle;
/*! \brief the array handle */
typedef TVMArray* TVMArrayHandle;
/*!
 * \brief The stream that is specific to device
 * can be NULL, which indicates the default one.
 */
typedef void* TVMStreamHandle;

#ifdef __cplusplus
}  // TVM_EXTERN_C
#endif
#endif  // TVM_RUNTIME_C_RUNTIME_API_H_
