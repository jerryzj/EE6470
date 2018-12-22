cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME multi_riscv_core)
project(${PROJECT_NAME} CXX)
enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

## make VERBOSE=1
set(CMAKE_VERBOSE_MAKEFILE on)

## compiler option setting
set(CMAKE_BUILD_TYPE "NONE")

set(CMAKE_CXX_FLAGS_NONE "${CMAKE_CXX_FLAGS_NONE} -O2")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -ggdb3 -O2")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")

# set(SYSTEMC_CFLAGS "-DSC_INCLUDE_FX")
set(OPT_CFLAGS "-DCLOCK_PERIOD=1.0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -m64 ${SYSTEMC_CFLAGS} ${OPT_CFLAGS}")
set(CMAKE_LD_FLAGS "${CMAKE_LD_FLAGS} -m64")

## set library root
set(SYSTEMC_ROOT $ENV{SYSTEMC_HOME})
set(SCML_ROOT $ENV{SCML_HOME})
set(OVP_ROOT $ENV{IMPERAS_HOME})

set(SYSTEMC_INCLUDE64_DIR ${SYSTEMC_ROOT}/include)
set(SYSTEMC_LIB64_DIR -L${SYSTEMC_ROOT}/lib-linux64)
set(SYSTEMC_LIBRARIES systemc)

set(SCML_INCLUDE64_DIR ${SCML_ROOT}/include)
set(SCML_LIB64_DIR -L${SCML_ROOT}/lib-linux64)
set(SCML_LIBRARIES scml)

set(OVP_INCLUDE64_DIR ${OVP_ROOT}/ImperasLib/source
                      ${OVP_ROOT}/ImpPublic/include/host)
set(OVP_LIB64_DIR -L${OVP_ROOT}/bin/Linux64)
set(OVP_LIBRARIES RuntimeLoader)

add_subdirectory(src)
