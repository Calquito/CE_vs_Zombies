#ifndef CE_vs_Estudiantes_APPLICATION_H
#define CE_vs_Estudiantes_APPLICATION_H

#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include <vector>
#include "../Controlador/Juego.h"

class Application
{
public:
    Application();
    ~Application();

    Juego *J1 = new Juego();

    void loop();
    void update(double delta_time);
    void draw();
    void generar_zombie(int x, int y);
private:
    //varaiables generales
    int cont_zombie;
    int cont_planta;
    int cont_disparo;
    int cont_zombies;
    bool planta_presionada;

    //donde se almacenan las plantas del tablero
    SDL_Surface *list_surface_planta [20];
    SDL_Rect list_rect_planta[20];
    double list_x_planta[20];
    double list_y_planta[20];

    //donde se almacenan los disparos de las plantas del tablero
    SDL_Surface *list_surface_disparo [20];
    SDL_Rect list_rect_disparo[20];
    double list_x_disparo[20];
    double list_y_disparo[20];
    int tiempo_disparos[20];

    //donde se almacenan los zombies del tablero
    SDL_Surface *list_surface_zombie [60];
    SDL_Rect list_rect_zombie[60];
    double list_x_zombie[60];
    double list_y_zombie[60];

    //fondo
    SDL_Surface *m_image;
    SDL_Rect     m_image_position;
    double       m_image_x;
    double       m_image_y;

    //planta seleccionable
    SDL_Surface *planta1;
    SDL_Rect     planta1_position;
    double       planta1_x;
    double       planta1_y;

    //vetana principal
    SDL_Window  *m_window;
    SDL_Surface *m_window_surface;
    SDL_Event    m_window_event;
};

#endif //CE_vs_Estudiantes_APPLICATION_H