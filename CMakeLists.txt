cmake_minimum_required(VERSION 3.13)
project(main)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(
        main
        common.cpp common.h
        func.cpp func.h
        main.cpp
        Makefile
        Student_info.cpp Student_info.h
        Stock.cpp Stock.h
        My_vector.cpp My_vector.h
        My_stack.h
        StringBad.cpp StringBad.h
        vec.cpp vec.h
        Str.cpp Str.h
        Sales_item.cpp Sales_item.h
        Screen.cpp Screen.h
        Window_mgr.cpp Window_mgr.h
        My_Queue.cpp My_Queue.h
        Brass_model.cpp Brass_model.h
        My_array.h
        My_pair.h
        LinkList.cpp LinkList.h
        Tree.cpp Tree.h)
