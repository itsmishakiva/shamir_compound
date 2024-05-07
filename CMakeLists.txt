cmake_minimum_required(VERSION 3.27)
project(lab_2)

find_package(Boost)

include_directories(${Boost_INCLUDE_DIR})

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_3 main.cpp
        shamir_separation.cpp
        shamir_separation.h
        shamir_compound.cpp
        shamir_compound.h
        big_math_functions.cpp
        big_math_functions.h
        random_generator.cpp
        random_generator.h
        secret_part.cpp
        secret_part.h)
