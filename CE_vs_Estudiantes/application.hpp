#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <memory>

class Application
{
public:
    Application();
    ~Application();

    void loop();
    void update(double delta_time);
    void draw();
private:
    int cont;

    SDL_Surface *list_surface [20];
    SDL_Rect list_rect[20];
    double list_x[20];
    double list_y[20];


    SDL_Surface *m_image;
    SDL_Rect     m_image_position;
    double       m_image_x;
    double       m_image_y;

    SDL_Surface *zombie1;
    SDL_Rect     zombie1_position;
    double       zombie1_x;
    double       zombie1_y;

    SDL_Surface *zombie2;
    SDL_Rect     zombie2_position;
    double       zombie2_x;
    double       zombie2_y;

    SDL_Surface *zombie3;
    SDL_Rect     zombie3_position;
    double       zombie3_x;
    double       zombie3_y;

    SDL_Surface *zombie4;
    SDL_Rect     zombie4_position;
    double       zombie4_x;
    double       zombie4_y;

    SDL_Surface *zombie5;
    SDL_Rect     zombie5_position;
    double       zombie5_x;
    double       zombie5_y;

    SDL_Surface *zombie6;
    SDL_Rect     zombie6_position;
    double       zombie6_x;
    double       zombie6_y;

    SDL_Surface *zombie7;
    SDL_Rect     zombie7_position;
    double       zombie7_x;
    double       zombie7_y;

    SDL_Surface *zombie8;
    SDL_Rect     zombie8_position;
    double       zombie8_x;
    double       zombie8_y;

    SDL_Surface *zombie9;
    SDL_Rect     zombie9_position;
    double       zombie9_x;
    double       zombie9_y;

    SDL_Surface *zombie10;
    SDL_Rect     zombie10_position;
    double       zombie10_x;
    double       zombie10_y;

    SDL_Window  *m_window;
    SDL_Surface *m_window_surface;
    SDL_Event    m_window_event;
};