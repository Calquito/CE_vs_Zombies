/**
 * @file Estudiante.h
 * @version 1.0
 * @date 01/11/2019
 * @author Allan Calderón
 * @title Clase de Estudiantes
 * @brief Clase de estudianes
 * */


#ifndef TECVSZOMBIES_ESTUDIANTE_H
#define TECVSZOMBIES_ESTUDIANTE_H


#include "../Cursos/Pos.h"
#include "../Controlador/List_Posiciones.h"

class Estudiante {
public:

    /**
    * @brief El constructor de estudiante
    * */
    Estudiante(int tipo, int life, int speed, int arqueros, int magos, int artilleros, int fuego){
        this->tipo = tipo;
        this->vida = life;
        this->velocidad = speed;
        this->resArqueros = arqueros;
        this->resMagos = magos;
        this->resArtilleros = artilleros;
        this->resFuego = fuego;
    }
    /**
    * @brief getVida es el método que retorna el argumento vida
    * */
    int getVida(){
        return this->vida;
    }
    /**
    * @brief restarVida es el metodo de reducir la vida
    * @param dano es el atributo de cuanto daño se hace
    * */
    void restarVida(int dano) {
        this->vida -= dano;
    }
    /**
    * @brief getSpeed es el método que retorna la velocidad del estudiante
    * */
    int getSpeed(){
        return this->velocidad;
    }

    /**
    * @brief getTipo es el método que retorna la velocidad del estudiante
    * */
    int getTipo(){
        return this->tipo;
    }

    /**
    * @brief setTipo es el metodo para definir el tipo de estudiante
    * @param tipo2 es el tipo que se definirá nuevo
    * */
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



#endif //TECVSZOMBIES_ESTUDIANTE_H
