cmake_minimum_required(VERSION 3.25)

project(EasyX)

set(CMAKE_CXX_STANDARD 17)

message("Project Path: ${CMAKE_CURRENT_SOURCE_DIR}\n")

link_libraries(
        "${CMAKE_CURRENT_SOURCE_DIR}/lib64/libeasyx.a"
)

add_executable(
        EasyX

        include/ChessBoardUI.h
        include/ChessBoardInit.h

        src/main.cpp
        src/ChessBoardUI.cpp
        src/ChessBoardInit.cpp
)

