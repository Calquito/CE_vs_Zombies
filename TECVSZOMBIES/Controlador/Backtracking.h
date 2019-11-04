/**
 * @file Backtracking.h
 * @version 1.0
 * @date 01/11/2019
 * @author Isaac Araya
 * @title Algoritmo de Backtraking
 * @brief Ayuda a encontrar rutas de un punto a otro
 * */

#ifndef TECVSZOMBIES_BACKTRACKING_H
#define TECVSZOMBIES_BACKTRACKING_H

#include <stdio.h>
#include "List_Posiciones.h"

using namespace std;

/**
 * @brief Clase de algoritmo backtracking
 * */

class Backtracking {


    int counter = 0;
    bool step (int x, int y,int maze[12][12]) {
        counter++;

        if (maze[x][y] == 2) {
            matrizSol[x][y]=3;
            path->insert(x, y);
            return true;
        }

        if (maze[x][y] == 0 || maze[x][y]==3 || maze[x][y] == 8) {
            return false;
        }

        maze[x][y]=3;
        matrizSol[x][y]=3;
        path->insert(x, y);
        bool result;

        if(maze[x-1][y] != 0 && maze[x-1][y]!=3 && maze[x-1][y] != 8){
            result = step(x-1, y,maze);
            if (result) { return true;}
        }

        else if(maze[x][y-1] != 0 && maze[x][y-1]!=3 && maze[x][y-1] != 8){
            result = step(x, y-1,maze);
            if (result) { return true;}
        }

        if(maze[x][y+1] != 0 && maze[x][y+1]!=3 && maze[x][y+1] != 8){
            result = step(x, y+1,maze);
            if (result) { return true;}
        }

        if(maze[x+1][y] != 0 && maze[x+1][y]!=3 && maze[x+1][y] != 8){
            result = step(x+1, y,maze);
            if (result) { return true;}
        }




        maze[x][y] = 8;
        matrizSol[x][y]=8;
        path->removeLastNode();

        return false;
    }


public:
    List_Posiciones* path=new List_Posiciones;
    List_Posiciones * solve(int x, int y,int maze[12][12]) {

        if (step(x,y,maze)) {
            matrizSol[x][y]=4;
        }
        return path;
    }



    int matrizSol[12][12]={ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }};

};


#endif //TECVSZOMBIES_BACKTRACKING_H
