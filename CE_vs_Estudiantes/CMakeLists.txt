cmake_minimum_required(VERSION 3.15)
project(CE_vs_Estudiantes)

set(CMAKE_CXX_STANDARD 14)

add_executable(CE_vs_Estudiantes main.cpp application.cpp application.hpp)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES})