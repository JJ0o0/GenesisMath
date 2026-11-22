cmake_minimum_required(VERSION 3.23)
project(
    GenesisMath
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(GENESIS_MATH_BUILD_TESTS "Build GenesisMath tests" OFF)

if(GENESIS_MATH_BUILD_TESTS AND NOT TARGET GTest::gtest_main)
    message(STATUS "Installing GoogleTest using FetchContent")
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        063de7e9578f82b369302001269680b4b1553359 # v1.18.0
    )

    if(WIN32)
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    endif()
    
    FetchContent_MakeAvailable(googletest)
    message(STATUS "Installed GoogleTest using FetchContent")
endif()

add_library(genesismath INTERFACE)
add_library(genesis::math ALIAS genesismath)

target_sources(genesismath PUBLIC
    FILE_SET HEADERS
        BASE_DIRS src
        FILES 
            src/genesis/math.hpp
)

target_compile_options(genesismath
    INTERFACE
        -Wall -Wextra
)

if(GENESIS_MATH_BUILD_TESTS)
    message(STATUS "Building Tests")
    enable_testing()
    add_subdirectory(tests)
endif()