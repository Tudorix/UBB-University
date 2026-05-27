cmake_minimum_required(VERSION 4.2)
project(Simul)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

include_directories(.)

add_executable(Simul
        Repo.cpp
        Repo.h
        Service.cpp
        Service.h
        Valid.cpp
        Valid.h
        GUI.cpp
        GUI.h
        main.cpp
        test.cpp
        test.h
        Produs.cpp
        Produs.h
)

target_link_libraries(Simul PRIVATE Qt6::Widgets)