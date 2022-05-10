cmake_minimum_required(VERSION 3.22)
project(Lista4Ex3 C)

set(CMAKE_C_STANDARD 99)

set (CMAKE_C_FLAGS "-m64 -static-libgcc -ggdb -g")

add_executable(Lista4Ex3 main.c artlib.c artlib.h naofiz.c naofiz.h)
