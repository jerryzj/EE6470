## make hello
add_custom_target(hello
                  COMMAND ../../platform/build/multi_core.plat ./hello.app
                  WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
)

add_executable(hello.app hello.c ../lib/crt0.s)
target_link_libraries(hello.app sync)
