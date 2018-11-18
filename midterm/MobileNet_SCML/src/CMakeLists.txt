include_directories(${SCML_INCLUDE64_DIR})
include_directories(${SYSTEMC_INCLUDE64_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(acc_platform)
add_subdirectory(dma)
add_subdirectory(memory)
add_subdirectory(conv_engine)
add_subdirectory(testbench)

## make run
add_custom_target(run
                  COMMAND ./conv
                  WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
)

file(GLOB src main.cpp)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
add_executable(conv ${src})
target_link_libraries(conv acc_platform_lib
                              dma_lib
                              conv_engine_lib
                              memory_lib
                              testbench_lib
                              ${SYSTEMC_LIB64_DIR} ${SYSTEMC_LIBRARIES}
                              ${SCML_LIB64_DIR} ${SCML_LIBRARIES}
)
