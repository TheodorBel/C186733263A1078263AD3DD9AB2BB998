cmake_minimum_required(VERSION 3.22)
project(database C)

set(CMAKE_C_STANDARD 11)

add_executable(database
        main.c source.c db.h)
