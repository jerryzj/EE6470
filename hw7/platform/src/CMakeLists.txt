include_directories(${SCML_INCLUDE64_DIR})
include_directories(${SYSTEMC_INCLUDE64_DIR})
include_directories(${OVP_INCLUDE64_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(acc_platform)
add_subdirectory(dma)
add_subdirectory(memory)
add_subdirectory(pool_engine)
add_subdirectory(cpu_core)

## make hello
add_custom_target(hello
                  COMMAND ./pooling.plat ../../application/build/hello_world.app
                  WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
)

## make hw
add_custom_target(hw
                  COMMAND ./pooling.plat ../../application/build/pooling_hw_test.app
                  WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
)

## make sw
add_custom_target(sw
                  COMMAND ./pooling.plat ../../application/build/pooling_sw_test.app
                  WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
)

file(GLOB src main.cpp)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
add_executable(pooling.plat ${src})
target_link_libraries(pooling.plat acc_platform_lib
                                   dma_lib
                                   pool_engine_lib
                                   memory_lib
                                   cpu_core_lib
                                   ${SYSTEMC_LIB64_DIR} ${SYSTEMC_LIBRARIES}
                                   ${SCML_LIB64_DIR} ${SCML_LIBRARIES}
                                   ${OVP_LIB64_DIR} ${OVP_LIBRARIES}
)
