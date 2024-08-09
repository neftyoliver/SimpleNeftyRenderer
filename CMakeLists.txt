cmake_minimum_required(VERSION 3.28.0)
project(SimpleNeftyRenderer)


add_executable(
        SimpleRenderer

        include/simple_obj_reader.hpp
        include/program_global.hpp

        src/main.cpp
        src/program.cpp
        src/renderer.cpp


)

set_property(TARGET SimpleRenderer PROPERTY CXX_STANDARD 26)

target_include_directories(SimpleRenderer PUBLIC include)