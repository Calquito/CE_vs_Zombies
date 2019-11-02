#include <iostream>
#include "Interfaz/application.hpp"

int main()
{
    Juego *Game = new Juego();
    Game->IniciaJuego();

    Application app;
    app.J1 = Game;

    app.loop();

}