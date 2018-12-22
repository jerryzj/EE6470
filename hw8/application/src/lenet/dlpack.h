/*!
 *  Copyright (c) 2017 by Contributors
 * \file dlpack.h
 * \brief The common header of DLPack.
 */
#ifndef DLPACK_DLPACK_H_
#define DLPACK_DLPACK_H_


#include <stdint.h>
#include <stddef.h>

/*!
 * \brief The device type in DLContext.
 */
typedef enum {
  kDLCPU = 1,
  kDLGPU = 2,
  // kDLCPUPinned = kDLCPU | kDLGPU
  kDLCPUPinned = 3,
  kDLOpenCL = 4,
  kDLMetal = 8,
  kDLVPI = 9,
  kDLROCM = 10,
  kDLFirmware = 13,
} DLDeviceType;

/*!
 * \brief A Device context for Tensor and operator.
 */
typedef struct {
  /*! \brief The device type used in the device. */
  int device_type;
  /*! \brief The device index */
  int device_id;
} DLContext;

/*!
 * \brief The type code options DLDataType.
 */
typedef enum {
  kDLInt = 0U,
  kDLUInt = 1U,
  kDLFloat = 2U,
} DLDataTypeCode;

/*!
 * \brief The data type the tensor can hold.
 *
 *  Examples
 *   - float: type_code = 2, bits = 32, lanes=1
 *   - float4(vectorized 4 float): type_code = 2, bits = 32, lanes=4
 *   - int8: type_code = 0, bits = 8, lanes=1
 */
typedef struct {
  /*!
   * \brief Type code of base types.
   * We keep it uint8_t instead of DLDataTypeCode for minimal memory
   * footprint, but the value should be one of DLDataTypeCode enum values.
   * */
  uint8_t code;
  /*!
   * \brief Number of bits, common choices are 8, 16, 32.
   */
  uint8_t bits;
  /*! \brief Number of lanes in the type, used for vector types. */
  uint16_t lanes;
} DLDataType;

/*!
 * \brief Plain C Tensor object, does not manage memory.
 */
typedef struct {
  /*!
   * \brief The opaque data pointer points to the allocated data.
   *  This will be CUDA device pointer or cl_mem handle in OpenCL.
   *  This pointer is always aligns to 256 bytes as in CUDA.
   */
  void* data;
  /*! \brief The device context of the tensor */
  DLContext ctx;
  /*! \brief Number of dimensions */
  int ndim;
  /*! \brief The data type of the pointer*/
  DLDataType dtype;
  /*! \brief The shape of the tensor */
  int32_t* shape;
  /*!
   * \brief strides of the tensor,
   *  can be NULL, indicating tensor is compact.
   */
  int32_t* strides;
  /*! \brief The offset in bytes to the beginning pointer to data */
  uint32_t byte_offset;
} DLTensor;

#endif  // DLPACK_DLPACK_H_
