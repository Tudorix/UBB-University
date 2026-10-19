cmake_minimum_required(VERSION 3.28)
project(SubSim)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(SubSim
        main.cpp
        GUI.cpp
        Repo.cpp
        Service.cpp
        Rochie.cpp
        Valid.cpp
        Valid.h
        test.cpp
        test.h
)

target_link_libraries(SubSim PRIVATE Qt6::Widgets)

target_compile_options(SubSim PRIVATE
        -Wall
        -Wextra
        -Wpedantic
)