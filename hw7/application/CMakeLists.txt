cmake_minimum_required(VERSION 3.0)

set(CMAKE_TOOLCHAIN_FILE cmake/Toolchain-archc-riscv.cmake
    CACHE FILEPATH "The crosscompiler setting file")

set(PROJECT_NAME riscv_apps)
project(${PROJECT_NAME} C CXX ASM)

## make VERBOSE=1
set(CMAKE_VERBOSE_MAKEFILE on)

## compiler option setting
set(CMAKE_BUILD_TYPE "DEBUG")
set(CMAKE_C_FLAGS_DEBUG "-ggdb3")
set(CMAKE_CXX_FLAGS_DEBUG ${CMAKE_C_FLAGS_DEBUG})

set(COMMON_FLAGS "-O2")
set(CMAKE_C_FLAGS "${COMMON_FLAGS}")
set(CMAKE_CXX_FLAGS "${COMMON_FLAGS}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(src)
