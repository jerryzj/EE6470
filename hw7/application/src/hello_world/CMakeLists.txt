## make hello
add_custom_target(hello
                  COMMAND ../../platform/build/pooling.plat ./hello_world.app
                  WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
)

FILE(GLOB src *.cpp)
add_executable(hello_world.app ${src})
target_link_libraries(hello_world.app)
