//
// Created by isaac4918 on 16/10/19.
//

#ifndef TECVSZOMBIES_CURSO_H
#define TECVSZOMBIES_CURSO_H

#include "Pos.h"


class Curso {
public:
    Curso(int tipo, int creditos, int nivel, int horas, int cooldown, int alcance){
        this->tipo = tipo;
        this->creditos = creditos;
        this->nivel = nivel;
        this->horas = horas;
        this->cooldown = cooldown;
        this->alcaEvaluacion = alcance;
    }
    int getCreditos(){
        return this->creditos;
    }

    int getCooldown(){
        return this->cooldown;
    }

    int getHoras(){
        return this->horas;
    }
    int getNivel(){
        return this->nivel;
    }
    int getAlcance(){
        return this->alcaEvaluacion;
    }
    int getTipo(){
        return this->tipo;
    }
    void setPos(int x, int y){
        this->pos->x = x;
        this->pos->y = y;
    }
    Curso *next;
    Pos *pos = new Pos();
    void upgrade();


private:
    int tipo;
    int creditos;
    int horas;
    int nivel;
    int alcaEvaluacion;
    int cooldown;
};

#endif //TECVSZOMBIES_CURSO_H
