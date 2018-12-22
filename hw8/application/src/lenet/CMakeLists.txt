## make lenet
add_custom_target(lenet
                  COMMAND ../../platform/build/pooling.plat ./lenet.app
                  WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
)

FILE(GLOB src *.cpp)
add_executable(lenet.app ${src})
target_link_libraries(lenet.app)
