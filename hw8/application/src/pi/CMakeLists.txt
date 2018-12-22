## make pi
add_custom_target(pi
                  COMMAND ../../platform/build/multi_core.plat ./pi.app
                  WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
)

add_executable(pi.app pi.c ../lib/crt0.s)
target_link_libraries(pi.app sync)
