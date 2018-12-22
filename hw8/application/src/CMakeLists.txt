include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)
include_directories(${CMAKE_SOURCE_DIR}/../platform/src/acc_platform)

FILE(GLOB CRT_OBJ_FILES ${RISCV_GCC_PATH}/lib/gcc/riscv32-unknown-elf/7.1.1/crt*.o)

add_subdirectory(lib)
add_subdirectory(hello)
add_subdirectory(pi)
add_subdirectory(pi_cxx)
add_subdirectory(lenet)
