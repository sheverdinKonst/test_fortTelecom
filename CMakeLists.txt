cmake_minimum_required(VERSION 3.26)
project(main_app C)

set(CMAKE_C_STANDARD 11)

add_executable(main_app main_app/main_client.c
        modules/project.h
        modules/morseCode.c
        modules/utils.c
        modules/server.c
        modules/client.c)
