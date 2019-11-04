/**
 * @file Curso.h
 * @version 1.0
 * @date 01/11/2019
 * @author Allan Calderón
 * @title Cursos
 * @brief Estructura de cursos
 * */

#ifndef TECVSZOMBIES_CURSO_H
#define TECVSZOMBIES_CURSO_H

#include "Pos.h"


class Curso {
public:
    /**
     *@brief Curso es el constructor de la clase curso
     **/
    Curso(int tipo, int creditos, int nivel, int horas, int cooldown, int alcance){
        this->tipo = tipo;
        this->creditos = creditos;
        this->nivel = nivel;
        this->horas = horas;
        this->cooldown = cooldown;
        this->alcaEvaluacion = alcance;
    }

    /**
     *@brief getCreditos es el metodo que retorna la cantidad de créditos
     **/
    int getCreditos(){
        return this->creditos;
    }
    /**
     *@brief getCreditos es el metodo que retorna la cantidad de créditos
     **/
    int getCooldown(){
        return this->cooldown;
    }
    /**
     *@brief getCreditos es el metodo que retorna la cantidad de créditos
     **/
    int getHoras(){
        return this->horas;
    }
    /**
     *@brief getCreditos es el metodo que retorna la cantidad de créditos
     **/
    int getNivel(){
        return this->nivel;
    }
    /**
     *@brief getCreditos es el metodo que retorna la cantidad de créditos
     **/
    int getAlcance(){
        return this->alcaEvaluacion;
    }
    /**
     *@brief getCreditos es el metodo que retorna la cantidad de créditos
     **/
    int getTipo(){
        return this->tipo;
    }
    /**
     *@brief getCreditos es el metodo que retorna la cantidad de créditos
     **/
    void setPos(int x, int y){
        this->pos->x = x;
        this->pos->y = y;
    }

    Curso *next;
    Pos *pos = new Pos();

    /**
     *@brief getCreditos es el metodo que retorna la cantidad de créditos
     **/
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
