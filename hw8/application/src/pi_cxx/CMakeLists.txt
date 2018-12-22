## make pi
add_custom_target(pi_cxx
                  COMMAND ../../platform/build/multi_core.plat ./pi_cxx.app
                  WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
)

FILE(GLOB src *.cpp)

# These are necessary implementations supporting C++ features

add_executable(pi_cxx.app ../lib/crt0.s ${CRT_OBJ_FILES} ${src} )
target_link_libraries(pi_cxx.app sync)
