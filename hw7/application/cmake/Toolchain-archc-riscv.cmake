# References:
# https://gitlab.kitware.com/cmake/community/wikis/doc/cmake/CrossCompiling
# http://www.valvers.com/open-software/raspberry-pi/step03-bare-metal-programming-in-c-pt3/

# this one is important
SET(CMAKE_SYSTEM_NAME Generic)
#this one not so much
SET(CMAKE_SYSTEM_VERSION 1)

# specify the cross compiler
SET(CMAKE_C_COMPILER   riscv32-unknown-elf-gcc)
SET(CMAKE_CXX_COMPILER riscv32-unknown-elf-g++)

# search for programs in the build host directories
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# for libraries and headers in the target directories
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY NEVER)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE NEVER)
