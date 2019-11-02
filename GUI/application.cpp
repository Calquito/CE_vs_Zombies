#include "application.hpp"
#include <cstdlib>
#include <math.h>
#include <unistd.h>

using namespace std;
/**
 * @brief carga una imagen y la coloca en una surface
 * @param path indica la ruta en la que se encuentra el bmp a cargar
 * @return retorna la superficie con la imagen cargada
 */

SDL_Surface *load_surface(char const *path)
{
    SDL_Surface *image_surface = SDL_LoadBMP(path);

    if(!image_surface)
        return 0;

    return image_surface;
}

/**
 * @brief inicializa ventana y variables iniciales
 * @return nada, inicializa variables
 */
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

    //definicion de variables generales
    planta_presionada=false;
    cont_zombie=0;
    cont_zombies=0;
    cont_planta=0;
    cont_disparo=0;


    m_image = load_surface("/home/allan/Desktop/Prueba/GUI/tablero.bmp");
    m_image_position.x = 0;
    m_image_position.y = 0;
    m_image_position.w = 641;
    m_image_position.h = 604;
    m_image_x = 0.0;
    m_image_y = 0.0;

    planta1= load_surface("/home/allan/Desktop/Prueba/GUI/Lanzagisantes.bmp");
    planta1_position.x = 550;
    planta1_position.y = 380;
    planta1_position.w = 26;
    planta1_position.h = 27;
    planta1_x = 550;
    planta1_y = 380;


}

Application::~Application()
{
    SDL_FreeSurface(m_window_surface);
    SDL_DestroyWindow(m_window);
}

/**
 * @brief genera zombie en la posicion especificada
 * @param x posicion inicial en x
 * @param posicion inicial en y
 * @return nada, carga el nuevo zombie en la lista de zombies
 */
void Application::generar_zombie(int x, int y){
    SDL_Surface *nuevo_zombie;
    SDL_Rect     nuevo_zombie_position;
    double       nuevo_zombie_x;
    double       nuevo_zombie_y;
    nuevo_zombie = load_surface("/home/allan/Desktop/Prueba/GUI/zombie.bmp");
    nuevo_zombie_position.x=x*53;
    nuevo_zombie_position.y=y*53;
    nuevo_zombie_position.w = 26;
    nuevo_zombie_position.h = 27;
    nuevo_zombie_x = x*53;
    nuevo_zombie_y = y*53 ;
    list_surface_zombie[cont_zombie] = nuevo_zombie;
    list_rect_zombie[cont_zombie] = nuevo_zombie_position;
    list_x_zombie[cont_zombie] = nuevo_zombie_x;
    list_y_zombie[cont_zombie] = nuevo_zombie_y;
    cont_zombie+=1;


}
/**
 * @brief loop del juego, lo mantiene corriendo, genera zombies cuando es necesario y permite colocar plantas en el tablero
 * @return nada, mantiene el juego corriendo
 */
void Application::loop()
{
    bool keep_window_open = true;
    while(keep_window_open)
    {
        while(SDL_PollEvent(&m_window_event) > 0)
        {    SDL_Surface *list_surface_disparo [20];
            SDL_Rect list_rect_disparo[20];
            double list_x_disparo[20];
            double list_y_disparo[20];
            switch(m_window_event.type)
            {
                case SDL_QUIT:
                    keep_window_open = false;
                    break;
            }
        }

        int r = (rand() % 1000) + 1;


        //presionar planta
        int x;
        int y;
        /*SDL_PumpEvents();
        SDL_Log("Mouse Button 1 (left) is pressed.");
        printf("Decimals: %d %ld\n", x,y);*/
        if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
            if( x>550 && x<576 && y>377 && y<415) {
                planta_presionada=true;
                usleep(100000);

                //printf("planta presionada");
            }
        }

        //generar nueva planta y controlarla
        if(planta_presionada) {
            if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT) && x<535) {
                //posicion en la que se pondra la planta
                int pos_casilla_x = x /53;
                int pos_casilla_y = y /53;
                int casilla_x=pos_casilla_x*53+5;
                int casilla_y=pos_casilla_y*53+26;

                J1->Tablero[pos_casilla_x][pos_casilla_y] = 0;

                //nueva planta
                SDL_Surface *nueva_planta;
                SDL_Rect nueva_planta_position;
                double nueva_planta_x;
                double nueva_planta_y;

                nueva_planta = load_surface("/home/allan/Desktop/Prueba/GUI/Lanzagisantes.bmp");
                nueva_planta_position.x = casilla_x ;
                nueva_planta_position.y = casilla_y ;
                nueva_planta_position.w = 26;
                nueva_planta_position.h = 27;
                nueva_planta_x =  casilla_x;
                nueva_planta_y = casilla_y ;

                list_surface_planta[cont_planta] = nueva_planta;
                list_rect_planta[cont_planta] = nueva_planta_position;
                list_x_planta[cont_planta] = nueva_planta_x;
                list_y_planta[cont_planta] = nueva_planta_y;

                //nuevo disparo
                SDL_Surface *nuevo_disparo;
                SDL_Rect nuevo_disparo_position;
                double nuevo_disparo_x;
                double nuevo_disparo_y;

                nuevo_disparo = load_surface("/home/allan/Desktop/Prueba/GUI/pregunta.bmp");
                nuevo_disparo_position.x = casilla_x ;
                nuevo_disparo_position.y = casilla_y ;
                nuevo_disparo_position.w = 26;
                nuevo_disparo_position.h = 27;
                nuevo_disparo_x =  casilla_x;
                nuevo_disparo_y = casilla_y ;

                list_surface_disparo[cont_disparo] = nuevo_disparo;
                list_rect_disparo[cont_disparo] = nuevo_disparo_position;
                list_x_disparo[cont_disparo] = nuevo_disparo_x;
                list_y_disparo[cont_disparo] = nuevo_disparo_y;
                tiempo_disparos[cont_disparo]=0;

                //condiciones finales
                cont_planta += 1;
                cont_disparo += 1;
                planta_presionada = false;
            }

        }

        if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
            if( x>0 && x<100 && y>0 && y<100) {
                J1->generaOleadas();
                for(int i = 0; i< J1->oleadaActual.size(); i++){
                    Estudiante *tmp = J1->Estudiantes->index(J1->oleadaActual[i]);
                    J1->encuentreRutas();
                    generar_zombie(tmp->pos->y,tmp->pos->x);
                }
                sleep(1);
            }
        }

        update(1.0 / 40.0);
        draw();
    }
}

/**
 * @brief actualiza los elementos con movimiento 
 * @param delta_time funciona similar a un delay(), controla el tiempo entre cada nueva actualizacion
 * @param file indica cual archivo se debe abrir
 * @return nada, modifica los objetos en la lista
 */
void Application::update(double delta_time)
{

    int i=0;
    while(i<cont_disparo){
        list_y_disparo[i] = list_y_disparo[i] + (5 * delta_time);
        list_rect_disparo[i].y =list_y_disparo[i];
        i++;
    }

    int j=0;
    while(j<cont_zombie){
        //std::cout<<list_x_zombie[j];
        /*
        int pos = aux[j];
        Estudiante *tmp = J1->Estudiantes->index(pos);
        int x = tmp->path->GetNth(0)->y;
        int y = tmp->path->GetNth(0)->x;*/

        list_y_zombie[j] = list_y_zombie[j] - (5 * delta_time);
        list_rect_zombie[j].y =list_y_zombie[j];
        j++;
    }

}

/**
 * @brief imprime los elementos en la pantalla
 * @return nada, imprime los objetos en la pantalla
 */

void Application::draw()
{
    SDL_FillRect(m_window_surface, NULL, SDL_MapRGB(m_window_surface->format, 0, 0, 0));
    SDL_BlitSurface(m_image, NULL, m_window_surface, &m_image_position);

    //revisar lista de plantas
    int i=0;
    while(i<cont_planta){
        SDL_BlitSurface(list_surface_planta[i], NULL, m_window_surface, &list_rect_planta[i]);
        SDL_BlitSurface(list_surface_disparo[i], NULL, m_window_surface, &list_rect_disparo[i]);
        i++;
    }

    //revisar lista de zombies
    int j=0;
    while(j<cont_zombie){
        SDL_BlitSurface(list_surface_zombie[j], NULL, m_window_surface, &list_rect_zombie[j]);
        j++;
    }

    SDL_BlitSurface(planta1, NULL, m_window_surface, &planta1_position);
    SDL_UpdateWindowSurface(m_window);
}