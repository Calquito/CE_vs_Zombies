//
// Created by isaac4918 on 16/10/19.
//

#ifndef CE_vs_Estudiantes_ESTUDIANTE_H
#define CE_vs_Estudiantes_ESTUDIANTE_H


#include "../Cursos/Pos.h"
#include "../Controlador/List_Posiciones.h"

class Estudiante {
public:
    Estudiante(int tipo, int life, int speed, int arqueros, int magos, int artilleros, int fuego){
        this->tipo = tipo;
        this->vida = life;
        this->velocidad = speed;
        this->resArqueros = arqueros;
        this->resMagos = magos;
        this->resArtilleros = artilleros;
        this->resFuego = fuego;
    }

    int getVida(){
        return this->vida;
    }
    void restarVida(int dano) {
        this->vida -= dano;
    }
    int getSpeed(){
        return this->velocidad;
    }
    int getTipo(){
        return this->tipo;
    }
    void setTipo(int tipo2){
        this->tipo = tipo2;
    }

    Estudiante *next;
    Pos *pos = new Pos();
    int tipo;
    int vida;
    int velocidad;
    int resArqueros;
    int resMagos;
    int resArtilleros;
    int resFuego;

    List_Posiciones *path = new List_Posiciones();


    void setPos(int x, int y){
        this->pos->x = x;
        this->pos->y = y;
    }

};



#endif //CE_vs_Estudiantes_ESTUDIANTE_H
