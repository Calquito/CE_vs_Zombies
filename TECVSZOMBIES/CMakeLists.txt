cmake_minimum_required(VERSION 3.14)
project(TECVSZOMBIES)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(TECVSZOMBIES main.cpp Controlador/GeneticAlg.cpp Controlador/GeneticAlg.h Controlador/Juego.cpp Controlador/Juego.h
        Cursos/Curso.h Cursos/Curso.cpp Estudiantes/Estudiante.h Estudiantes/Estudiante.cpp Estructuras/ListaCursos.cpp Estructuras/ListaCursos.h Estructuras/ListaEstudiantes.cpp Estructuras/ListaEstudiantes.h Cursos/Pos.cpp Cursos/Pos.h Controlador/Backtracking.cpp Controlador/Backtracking.h Controlador/Matriz.cpp Controlador/Matriz.h Controlador/List_Posiciones.cpp Controlador/List_Posiciones.h Controlador/Pathfinding.cpp Controlador/Pathfinding.h)

# Look for required libraries
set(requiredlibs)

find_package(CURL)
if(CURL_FOUND)
    include_directories(${CURL_INCLUDE_DIR})
    set(requiredlibs ${requiredlibs} ${CURL_LIBRARIES} )
else(CURL_FOUND)
    message(FATAL_ERROR "Could not find the CURL library and development files.")
endif(CURL_FOUND)


set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp)

set(CURL_LIBRARY "-lcurl")
find_package(CURL REQUIRED)
include_directories(./include)


pkg_check_modules(GTK3 REQUIRED gtk+-3.0 gmodule-2.0 )


include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
include_directories(./include)


add_definitions(${GTK3_CFLAGS_OTHER})

target_link_libraries(TECVSZOMBIES ${GTK3_LIBRARIES})


include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(TECVSZOMBIES ${CURL_LIBRARIES})
