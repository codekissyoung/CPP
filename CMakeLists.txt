cmake_minimum_required(VERSION 3.13)
project(CPP)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(CPP
        common.cpp
        common.h
        func.cpp
        main.cpp
        Makefile
        median.cpp
        median.h
        stock.cpp
        stock.h
        vector.cpp
        vector.h
        container.cpp
        container.h
        date.h
        date.cpp
        stack.h
        stack.cpp)
