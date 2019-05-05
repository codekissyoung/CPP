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
        student.cpp student.h
        stock.cpp stock.h
        vector.cpp vector.h
        date.h date.cpp
        stack.h stack.cpp
        my_string.cpp my_string.h
        vec.cpp vec.h
        Str.cpp Str.h
        Sales_item.cpp Sales_item.h
        Sales_data.cpp Sales_data.h
        Screen.cpp Screen.h
        Window_mgr.cpp Window_mgr.h
)
