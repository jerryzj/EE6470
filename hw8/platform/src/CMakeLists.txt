include_directories(${SCML_INCLUDE64_DIR})
include_directories(${SYSTEMC_INCLUDE64_DIR})
include_directories(${OVP_INCLUDE64_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/acc_platform)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/multi_cpu_core)

add_subdirectory(acc_platform)
add_subdirectory(multi_cpu_core)

## make hello
add_custom_target(hello
                  COMMAND ./multi_core.plat ../../application/build/hello.app
                  WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
)

## make pi
add_custom_target(pi
                  COMMAND ./multi_core.plat ../../application/build/pi.app
                  WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
)

file(GLOB src main.cpp)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
add_executable(multi_core.plat ${src})
target_link_libraries(multi_core.plat acc_platform_lib
                                      dma_lib
                                      memory_lib
                                      pool_engine_lib
                                      cpu_core_lib
                                      scml_bridge_lib
                                      ${SYSTEMC_LIB64_DIR} ${SYSTEMC_LIBRARIES}
                                      ${SCML_LIB64_DIR} ${SCML_LIBRARIES}
                                      ${OVP_LIB64_DIR} ${OVP_LIBRARIES}
)
