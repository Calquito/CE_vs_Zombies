cmake_minimum_required(VERSION 3.15)
project(CE_vs_Estudiantes)

set(CMAKE_CXX_STANDARD 14)

add_executable(CE_vs_Estudiantes main.cpp Interfaz/application.cpp Interfaz/application.hpp Controlador/GeneticAlg.cpp Controlador/GeneticAlg.h Controlador/Juego.cpp Controlador/Juego.h
        Cursos/Curso.h Cursos/Curso.cpp Estudiantes/Estudiante.h Estudiantes/Estudiante.cpp Estructuras/ListaCursos.cpp Estructuras/ListaCursos.h Estructuras/ListaEstudiantes.cpp Estructuras/ListaEstudiantes.h Cursos/Pos.cpp Cursos/Pos.h Controlador/Backtracking.cpp Controlador/Backtracking.h Controlador/Matriz.cpp Controlador/Matriz.h Controlador/List_Posiciones.cpp Controlador/List_Posiciones.h Controlador/Pathfinding.cpp Controlador/Pathfinding.h)


INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES})