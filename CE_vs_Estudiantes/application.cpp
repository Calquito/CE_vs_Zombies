#include "application.hpp"
#include <cstdlib>

SDL_Surface *load_surface(char const *path)
{
    SDL_Surface *image_surface = SDL_LoadBMP(path);

    if(!image_surface)
        return 0;

    return image_surface;
}

Application::Application()
{
    m_window = SDL_CreateWindow("SDL2 Window",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                641, 604,
                                0);

    if(!m_window)
    {
        std::cout << "Failed to create window\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }

    m_window_surface = SDL_GetWindowSurface(m_window);

    if(!m_window_surface)
    {
        std::cout << "Failed to get window's surface\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }

    m_image = load_surface("/home/allan/Desktop/CE_vs_Estudiantes/tablero.bmp");
    m_image_position.x = 0;
    m_image_position.y = 0;
    m_image_position.w = 641;
    m_image_position.h = 604;
    m_image_x = 0.0;
    m_image_y = 0.0;

    cont=0;

    zombie1 = load_surface("/home/allan/Desktop/CE_vs_Estudiantes/zombie.bmp");
    zombie1_position.x = 13;
    zombie1_position.y = 604;
    zombie1_position.w = 26;
    zombie1_position.h = 43;
    zombie1_x = 13;
    zombie1_y = 604;

    zombie2 = load_surface("/home/allan/Desktop/CE_vs_Estudiantes/zombie.bmp");
    zombie2_position.x = 66;
    zombie2_position.y = 604;
    zombie2_position.w = 26;
    zombie2_position.h = 43;
    zombie2_x = 66;
    zombie2_y = 604;


    zombie3 = load_surface("/home/allan/Desktop/CE_vs_Estudiantes/zombie.bmp");
    zombie3_position.x = 119;
    zombie3_position.y = 604;
    zombie3_position.w = 26;
    zombie3_position.h = 43;
    zombie3_x = 119;
    zombie3_y = 604;

    zombie4 = load_surface("/home/allan/Desktop/CE_vs_Estudiantes/zombie.bmp");
    zombie4_position.x = 172;
    zombie4_position.y = 604;
    zombie4_position.w = 26;
    zombie4_position.h = 43;
    zombie4_x = 172;
    zombie4_y = 604;

    zombie5 = load_surface("/home/allan/Desktop/CE_vs_Estudiantes/zombie.bmp");
    zombie5_position.x = 225;
    zombie5_position.y = 604;
    zombie5_position.w = 26;
    zombie5_position.h = 43;
    zombie5_x = 225;
    zombie5_y = 604;

    zombie6 = load_surface("/home/allan/Desktop/CE_vs_Estudiantes/zombie.bmp");
    zombie6_position.x = 278;
    zombie6_position.y = 604;
    zombie6_position.w = 26;
    zombie6_position.h = 43;
    zombie6_x = 278;
    zombie6_y = 604;

    zombie7 = load_surface("/home/allan/Desktop/CE_vs_Estudiantes/zombie.bmp");
    zombie7_position.x = 331;
    zombie7_position.y = 604;
    zombie7_position.w = 26;
    zombie7_position.h = 43;
    zombie7_x = 331;
    zombie7_y = 604;

    zombie8 = load_surface("/home/allan/Desktop/CE_vs_Estudiantes/zombie.bmp");
    zombie8_position.x = 384;
    zombie8_position.y = 604;
    zombie8_position.w = 26;
    zombie8_position.h = 43;
    zombie8_x = 384;
    zombie8_y = 604;

    zombie9 = load_surface("/home/allan/Desktop/CE_vs_Estudiantes/zombie.bmp");
    zombie9_position.x = 437;
    zombie9_position.y = 604;
    zombie9_position.w = 26;
    zombie6_position.h = 43;
    zombie9_x = 437;
    zombie9_y = 604;

    zombie10 = load_surface("/home/allan/Desktop/CE_vs_Estudiantes/zombie.bmp");
    zombie10_position.x = 490;
    zombie10_position.y = 604;
    zombie10_position.w = 26;
    zombie10_position.h = 43;
    zombie10_x = 490;
    zombie10_y = 604;



}

Application::~Application()
{
    SDL_FreeSurface(m_window_surface);
    SDL_DestroyWindow(m_window);
}

void Application::loop()
{
    bool keep_window_open = true;
    while(keep_window_open)
    {
        while(SDL_PollEvent(&m_window_event) > 0)
        {
            switch(m_window_event.type)
            {
                case SDL_QUIT:
                    keep_window_open = false;
                    break;
            }
        }

        int r = (rand() % 100) + 1;

        update(1.0/40.0);
        draw();
    }
}

void Application::update(double delta_time)
{
    int random_number= ( std::rand() % ( 3  + 1 ) );


    zombie1_y = zombie1_y - (5 * delta_time);
    zombie1_position.y =zombie1_y;

    zombie2_y = zombie2_y - (5 * delta_time);
    zombie2_position.y =zombie2_y;

    zombie3_y = zombie3_y - (5 * delta_time);
    zombie3_position.y =zombie3_y;

    zombie4_y = zombie4_y - (5 * delta_time);
    zombie4_position.y =zombie4_y;

    zombie5_y = zombie5_y - (5 * delta_time);
    zombie5_position.y =zombie5_y;

    zombie6_y = zombie6_y - (5 * delta_time);
    zombie6_position.y =zombie6_y;

    zombie7_y = zombie7_y - (5 * delta_time);
    zombie7_position.y =zombie7_y;

    zombie8_y = zombie8_y - (5 * delta_time);
    zombie8_position.y =zombie8_y;

    zombie9_y = zombie9_y - (5 * delta_time);
    zombie9_position.y =zombie9_y;

    zombie10_y = zombie10_y - (5 * delta_time);
    zombie10_position.y =zombie10_y;

}

void Application::draw()
{
    SDL_FillRect(m_window_surface, NULL, SDL_MapRGB(m_window_surface->format, 0, 0, 0));
    SDL_BlitSurface(m_image, NULL, m_window_surface, &m_image_position);
    SDL_BlitSurface(zombie1, NULL, m_window_surface, &zombie1_position);
    SDL_BlitSurface(zombie2, NULL, m_window_surface, &zombie2_position);
    SDL_BlitSurface(zombie3, NULL, m_window_surface, &zombie3_position);
    SDL_BlitSurface(zombie4, NULL, m_window_surface, &zombie4_position);
    SDL_BlitSurface(zombie5, NULL, m_window_surface, &zombie5_position);
    SDL_BlitSurface(zombie6, NULL, m_window_surface, &zombie6_position);
    SDL_BlitSurface(zombie7, NULL, m_window_surface, &zombie7_position);
    SDL_BlitSurface(zombie8, NULL, m_window_surface, &zombie8_position);
    SDL_BlitSurface(zombie9, NULL, m_window_surface, &zombie9_position);
    SDL_BlitSurface(zombie10, NULL, m_window_surface, &zombie10_position);
    SDL_UpdateWindowSurface(m_window);
}