/***************************************************************************
 * Copyright 1996-2017 Synopsys, Inc.
 *
 * This Synopsys software and all associated documentation are proprietary
 * to Synopsys, Inc. and may only be used pursuant to the terms and
 * conditions of a written license agreement with Synopsys, Inc.
 * All other use, reproduction, modification, or distribution of the
 * Synopsys software or the associated documentation is strictly prohibited.
 ***************************************************************************/
/*
 * Modifications :
 *
 * Purpose of file : Utilities for scml_memory modeling object
 *
 */

#include "scml_memory_utils.h"
#include <iostream>
#include <cassert>


#if defined(sun) || defined(__sun)
// Solaris
#define __BYTE_ORDER 1234
#define __LITTLE_ENDIAN 4321
#else

#ifdef _WIN32
// Windows
/* On an Intel computer, the little end is stored first.
   This means a Hex word like 0x1234 is stored in memory
   as (0x34 0x12). The little end, or lower end, is stored first.
   The same is true for a four-byte value; for example,
   0x12345678 would be stored as (0x78 0x56 0x34 0x12),
   Windows NT was designed around Little Endian architecture.
*/
#define __LITTLE_ENDIAN 1234
#define __BYTE_ORDER __LITTLE_ENDIAN
#else
// Linux
#include <endian.h>
#endif // _WIN32

#endif // defined(sun) || defined(__sun)
 
namespace scml_memory_utils {
 
cwrMas defaultMas(unsigned int d)
{
  ::std::cerr << "Unsupported data size " << d << ::std::endl;
  assert( false);
  return cwrMas32;
}

bool hasHostEndianness( cwrEnd endianness)
{
  // see PSP_Utils/AddressRange.h
  //
  bool mHasHostEndianness;
  if (__BYTE_ORDER == __LITTLE_ENDIAN) {
    mHasHostEndianness = (endianness == cwrLitend);
  } else {
    mHasHostEndianness = (endianness != cwrLitend);
  }
  return mHasHostEndianness;
}


}
