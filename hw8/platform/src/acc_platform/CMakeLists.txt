add_subdirectory(dma)
add_subdirectory(memory)
add_subdirectory(pool_engine)

file(GLOB src *.cpp)
add_library(acc_platform_lib STATIC ${src})
