cmake_minimum_required(VERSION 3.13)
project(c___adv_as2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(c___adv_as2
        Document.cpp
        Document.hpp
        Editor.cpp
        Editor.hpp
        input.txt
        inputCRLF.txt
        POEM.txt
        test.txt)
