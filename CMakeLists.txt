
cmake_minimum_required(VERSION 3.16)

project (test)

# Replace these paths with the appropriate paths to your NLopt installation
set(NLOPT_INCLUDE_DIR "/path/to/nlopt/include")
set(NLOPT_LIB_DIR "/path/to/nlopt/lib")


add_executable (test main.cxx)

#include libraries
target_include_directories(test PRIVATE ${NLOPT_INCLUDE_DIR})

find_library(NLOPT_LIBRARY nlopt HINTS ${NLOPT_LIB_DIR})

#link Libraries
target_link_libraries(test PRIVATE ${NLOPT_LIBRARY})
