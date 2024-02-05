cmake_minimum_required(VERSION 3.21)

if (NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 20)
endif()

set(CMAKE_CXX_EXTENSIONS OFF)

project(
    demangler
    VERSION 0.0.1
    DESCRIPTION "Demangles both GCC and clang output"
    LANGUAGES CXX)

add_subdirectory(src)

# Don't look at tests if we're not top level
if(NOT PROJECT_IS_TOP_LEVEL)
    return()
endif()

