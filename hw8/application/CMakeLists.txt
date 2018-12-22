cmake_minimum_required(VERSION 3.0)

set(CMAKE_TOOLCHAIN_FILE cmake/Toolchain-riscv.cmake
    CACHE FILEPATH "The crosscompiler setting file")

set(PROJECT_NAME parallel_program)
project(${PROJECT_NAME} C CXX ASM)

## make VERBOSE=1
set(CMAKE_VERBOSE_MAKEFILE on)

## compiler option setting
set(CMAKE_BUILD_TYPE "DEBUG")
set(CMAKE_C_FLAGS_DEBUG "-ggdb3")
set(CMAKE_CXX_FLAGS_DEBUG ${CMAKE_C_FLAGS_DEBUG})

set(COMMON_FLAGS "-O2")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -nostartfiles")
set(CMAKE_CXX_FLAGS "${COMMON_FLAGS} -nostartfiles")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -march=rv32ia")

add_subdirectory(src)
