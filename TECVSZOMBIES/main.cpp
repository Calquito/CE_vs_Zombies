#include <iostream>
#include "Interfaz/application.hpp"

/**
 * @brief inicia el loop del juego
 * @return nada, inicia el juego
 */
int main()
{
    Juego *Game = new Juego();
    Game->IniciaJuego();

    Application app;
    app.J1 = Game;

    app.loop();

}