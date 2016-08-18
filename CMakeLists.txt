cmake_minimum_required(VERSION 3.6)
project(data_structures)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wreturn-type")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")


set(SOURCE_FILES)

set(TEST_FILES
        test/main.cpp)

include_directories(src)
include_directories(lib)

add_executable(data_structures ${SOURCE_FILES})
add_executable(run_tests ${SOURCE_FILES} ${TEST_FILES})