cmake_minimum_required(VERSION 3.28.0)
project(SimpleNeftyRenderer)


add_executable(
        SimpleRenderer

        include/program.h
        include/obj_file.h

        src/main.cpp
        src/program.cpp
        src/renderer.cpp
        src/obj_file.cpp


)

set_property(TARGET SimpleRenderer PROPERTY CXX_STANDARD 26)

target_include_directories(SimpleRenderer PUBLIC include)