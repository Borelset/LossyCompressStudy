cmake_minimum_required(VERSION 3.10)
project(SZ CXX C)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(sz/include)
include_directories(zlib)

aux_source_directory(sz/src SRC)
aux_source_directory(zlib ZLIB)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/build)

add_executable(compression ${SRC} ${ZLIB} example/testdouble_compress.c)

add_executable(decompression ${SRC} ${ZLIB} example/testdouble_decompress.c)
