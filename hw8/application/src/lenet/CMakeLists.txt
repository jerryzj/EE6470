## make lenet
add_custom_target(lenet
                  COMMAND ../../platform/build/multi_core.plat ./lenet.app
                  WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
)

FILE(GLOB src *.cpp)

# These are necessary implementations supporting C++ features

add_executable(lenet.app ../lib/crt0.s ${CRT_OBJ_FILES} ${src} )
target_link_libraries(lenet.app sync)
