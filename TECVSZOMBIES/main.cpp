#include <iostream>
#include "Controlador/Juego.h"


int main() {

    Juego *J1 = new Juego();
    J1->IniciaJuego();

    cout<<"========================="<<endl;
    cout<<"Posiciones:"<<endl;
    cout<<"========================="<<endl;
    for(int i = 0; i<J1->Estudiantes->lenght(); i++){
        cout<<"========================="<<endl;
        cout<< "X:" << endl;
        cout<<J1->Estudiantes->index(i)->pos->y<< endl;
        cout<< "Y:" <<endl;
        cout<<J1->Estudiantes->index(i)->pos->x<<endl;
        cout<<"========================="<<endl;
    }

    return 0;
}
