cmake_minimum_required(VERSION 4.2)
project(Lab6_7)

set(CMAKE_CXX_STANDARD 14)

find_package(Qt5 REQUIRED COMPONENTS Widgets)
include_directories(.)

add_executable(Lab6_7
        Exception.h
        GUI.cpp
        GUI.h
        main.cpp
        Produs.cpp
        Produs.h
        Repo.cpp
        Repo.h
        Service.cpp
        Service.h
        UI.cpp
        UI.h
        Undo.cpp
        Undo.h
        Valid.cpp
        Valid.h
        vector.h
        vector.tpp
        Wishlist.cpp
        Wishlist.h
        WishGUI.cpp
        WishGUI.h)


target_link_libraries(Lab6_7 PRIVATE Qt5::Widgets)