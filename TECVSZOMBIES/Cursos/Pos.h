/**
 * @file Pos.h
 * @version 1.0
 * @date 01/11/2019
 * @author Allan Calderón
 * @title Posiciones
 * @brief Estructura para almacenar posiciones
 * */


#ifndef TECVSZOMBIES_POS_H
#define TECVSZOMBIES_POS_H


class Pos{
public:

    /**
     * @brief Constructor básico
     * */
    Pos(){
    }

    /**
     * @brief Constructor con parámetros
     * @param x es la posicion x
     * @param y es la posicion y
     * */
    Pos(int x, int y){
        this->x = x;
        this->y = y;
    }
    int x;
    int y;
};


#endif //TECVSZOMBIES_POS_H
