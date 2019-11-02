//
// Created by isaac4918 on 23/10/19.
//

#include "Juego.h"
#include<iostream>
#include "Backtracking.h"

void Juego::hacerBacktracking(Estudiante *zombie) {
    auto tmp = this->Tablero;
    int a;
    a = 1 + rand() % (9);
    escribirMatriz(1,a,tmp);
    Backtracking backtracking;
    backtracking.solve(zombie->pos->x,zombie->pos->y, tmp)->display();
    zombie->path = backtracking.path;


}

void Juego::hacerPathfinding(Estudiante *zombie) {
    Pathfinding pathfinding;
    // Creating a shortcut for int, int pair type
    typedef pair<int, int> Pair;
    typedef pair<double, pair<int, int>> pPair;
    Pair src = make_pair(zombie->pos->x, zombie->pos->y);
    int a;
    a = 1 + rand() % (9);
    Pair dest = make_pair(1, a);

    pathfinding.aStarSearch(Tablero,src,dest)->display();
    zombie->path = pathfinding.listPosiciones;
}


void Juego::escribirMatriz(int x, int y, int matriz[12][12]){

    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            if (Tablero[x][y]==1){
                Tablero[x][y]=2;
            }
        }
    }
}
