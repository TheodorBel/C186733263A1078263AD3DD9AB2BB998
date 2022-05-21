cmake_minimum_required(VERSION 3.22)
project(querueueu C)

set(CMAKE_C_STANDARD 99)

add_executable(querueueu main.c "queru.h" "source.c" "../database/db.h" "../database/source.c")
