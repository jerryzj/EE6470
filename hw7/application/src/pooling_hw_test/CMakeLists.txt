## make hw
add_custom_target(hw
                  COMMAND ../../platform/build/pooling.plat ./pooling_hw_test.app
                  WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
)

FILE(GLOB src *.cpp)
add_executable(pooling_hw_test.app ${src})
target_link_libraries(pooling_hw_test.app)
