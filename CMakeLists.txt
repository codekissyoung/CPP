cmake_minimum_required(VERSION 3.13)
project(CPP)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(
        CPP
        common.cpp common.h
        func.cpp func.h
        main.cpp
        Makefile
        Student_info.cpp Student_info.h
        stock.cpp stock.h
        My_vector.cpp My_vector.h
        My_stack.h My_stack.cpp
        StringBad.cpp StringBad.h
        vec.cpp vec.h
        Str.cpp Str.h
        Sales_item.cpp Sales_item.h
        Screen.cpp Screen.h
        Window_mgr.cpp Window_mgr.h
)
