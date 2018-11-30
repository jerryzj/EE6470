## make sw
add_custom_target(sw
                  COMMAND ../../platform/build/pooling.plat ./pooling_sw_test.app
                  WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
)

FILE(GLOB src *.cpp)
add_executable(pooling_sw_test.app ${src})
target_link_libraries(pooling_sw_test.app)
