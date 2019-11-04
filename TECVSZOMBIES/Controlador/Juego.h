/**
 * @file Juego.h
 * @version 1.0
 * @date 01/11/2019
 * @author Isaac Araya
 * @title Controlador del Juego
 * @brief Maneja la mayoria de aspectos del juego
 * */

#ifndef TECVSZOMBIES_JUEGO_H
#define TECVSZOMBIES_JUEGO_H


#include <stdlib.h>
#include "GeneticAlg.h"
#include "../Estructuras/ListaCursos.h"
#include "../Estructuras/ListaEstudiantes.h"
#include "../Cursos/Curso.h"
#include "Pathfinding.h"
#include <string>
#include <vector>
#include <unistd.h>

using namespace std;

/**
 * @brief Clase de juego que contiene la logica del juego
 **/

class Juego {
public:
    int creditos = 18;
    int Tablero[12][12]= {
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    ListaCursos *Cursos = new ListaCursos();
    ListaEstudiantes *Estudiantes = new ListaEstudiantes();
    vector<int> zombiesEnviados;
    vector<int> oleadaActual;
    GeneticAlg *AG = new GeneticAlg();

    /**
     * @brief escribirMatriz es un método que coloca un número de salida para los algoritmos de backtracking
     * @param x es la posición x en la que se quiere que dar la salida
     * @param y es la posición y en la que se quiere dar la salida
     * @param matriz es la matriz sobre la que se realizará el algoritmo genético
     * */
    void escribirMatriz(int x,int y,  int matriz[12][12]);
    /**
     * @brief hacerBacktraking es un método que encuentra rutas por medio del algoritmo de backtracking
     * @param zombie es el objeto sobre el que se tiene la informacion para el origen y el destino y donde
     * se almacenará la ruta hallada
     * */
    void hacerBacktracking(Estudiante *zombie);
    /**
     * @brief hacerPathfinding es un método que encuentra rutas por medio del algoritmo A*
     * @param zombie es el objeto sobre el que se tiene la informacion para el origen y el destino y donde
     * se almacenará la ruta hallada
     * */
    void hacerPathfinding(Estudiante *zombie);
    /**
     * @brief generaEstudiantes es el metodo que genera la poblacion de estudiantes que almacena en una lista
     * */
    void generaEstudiantes(){
        srand(time(NULL));
        int x;
        x = 4 + rand() % (6);
        for(int i = 0; i<x; i++){
            Estudiante *ogro = new Estudiante(0, 100, 30, 65, 20, 20, 10);
            int a;
            a = 1 + rand() % (9);
            ogro->setPos(10, a);
            Estudiantes->insert(ogro);
        }
        x = 4 + rand() % (6);
        for(int i = 0; i<x; i++){
            Estudiante *Elfos = new Estudiante(1, 130, 50, 65, 65, 20, 20);
            int a;
            a = 1 + rand() % (9);
            Elfos->setPos(10, a);
            Estudiantes->insert(Elfos);
        }
        x = 3 + rand() % (6);
        for(int i = 0; i<x; i++){
            Estudiante *Harpias = new Estudiante(2, 160, 50, 100, 100, 25, 25);
            int a;
            a = 1 + rand() % (9);
            Harpias->setPos(10, a);
            Estudiantes->insert(Harpias);
        }
        x =2 + rand() % (4);
        for(int i = 0; i<x; i++){
            Estudiante *Mercenarios = new Estudiante(3, 200, 78, 78, 68, 68, 27);
            int a;
            a = 1 + rand() % (9);
            Mercenarios->setPos(10, a);
            Estudiantes->insert(Mercenarios);
        }
        Estudiantes->printL();
    }
    /**
     * @brief generaCurso es el metodo que genera un curso de un tipo determinado en una población determinada
     * @param tipo es el tipo de curso a generar
     * @param x es la posicion x del curso
     * @param y es la posicion y del curso
     * */
    void generaCurso(int tipo, int x, int y){
        if(this->creditos >0 && Tablero[y][x] != 0){
            if(tipo == 10 && this->creditos >= 1){//arqueros
                Curso *tmp = new Curso(10, 1, 1, 5, 2, 1);
                tmp->setPos(x,y);
                Cursos->insert(tmp);
                Tablero[y][x] = 0;
                this->creditos -= 1;
            }
            else if(tipo == 11 && this->creditos >= 2){//magos
                Curso *tmp = new Curso(11, 2, 2, 7, 2, 2);
                tmp->setPos(x,y);
                Cursos->insert(tmp);
                Tablero[y][x] = 0;
                this->creditos -= 2;
            }
            else if(tipo == 12 && this->creditos >= 3){//artilleros
                Curso *tmp = new Curso(12, 3, 3, 8, 3, 2);
                tmp->setPos(x,y);
                Cursos->insert(tmp);
                Tablero[y][x] = 0;
                this->creditos -= 3;
            }
            else if(tipo == 13 && this->creditos >= 4){//fuego
                Curso *tmp = new Curso(13, 4, 3, 9, 5, 3);
                tmp->setPos(x,y);
                Cursos->insert(tmp);
                Tablero[y][x] = 0;
                this->creditos -= 4;
            }
        }

    }

    /**
     * @brief evaluaciones es el metodo que realiza la evaluación de los estudiantes contra los cursos
     * @param E1 es el parámetro del que se obtiene la información del estudiante a evaluar
     * @param C1 es el parámetro del que se obtiene la información del curso que evalua
     * */

    void evaluaciones(Estudiante E1, Curso C1){
        int dmgCurso = C1.getHoras()*C1.getNivel()*C1.getCreditos();
        float porcentaje;
        if(C1.getTipo() == 10){
            porcentaje = (100-E1.resArqueros)/100;
            dmgCurso = dmgCurso*porcentaje;
            E1.vida -= (dmgCurso*porcentaje);
        }
        else if(C1.getTipo() == 11){
            porcentaje = (100-E1.resMagos)/100;
            dmgCurso = dmgCurso*porcentaje;
            E1.vida -= (dmgCurso*porcentaje);
        }
        else if(C1.getTipo() == 12){
            porcentaje = (100-E1.resArtilleros)/100;
            dmgCurso = dmgCurso*porcentaje;
            E1.vida -= (dmgCurso*porcentaje);
        }
        else if(C1.getTipo() == 13){
            porcentaje = (100-E1.resFuego)/100;
            dmgCurso = dmgCurso*porcentaje;
            E1.vida -= (dmgCurso*porcentaje);
        }

    }

    /**
     * @brief printTablero es un método para mostrar la matriz en consola
     * */

    void printTablero(){
        cout<<"================================================================================="<<endl;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 12; j++)
                printf(" %d ", Tablero[i][j]);
            printf("\n");
        }
        cout<<"================================================================================="<<endl;
    }

    /**
     * @brief IniciaJuego es el método que ejecuta las funciones básicas para el funcionamiento del juego
     * */

    void IniciaJuego() {
        generaEstudiantes();
        encuentreRutas();
        for(int i = 0; i < 6; i++){
            generaOleadas();
            printOleada();
            sleep(1);
        }
    }

    /**
     * @brief generaOleadas es el método que toma de la poblacion total de estudiantes y genera pequeñas oleadas
     * */

    void generaOleadas(){
        oleadaActual.clear();
        int a = rand() % (6);
        int tmp;
        int c = 0;
        while (c <= a && zombiesEnviados.size() != Estudiantes->lenght()){
            bool anadir = true;
            tmp =rand() % (Estudiantes->lenght());
            for(int i = 0; i<zombiesEnviados.size(); i ++){
                if(tmp == zombiesEnviados[i]){
                    anadir= false;
                }
            }
            if(anadir){
                zombiesEnviados.push_back(tmp);
                oleadaActual.push_back(tmp);
                c++;
            }

        }


    }
    /**
     * @brief printOleada es el método que permite ver las oleadas en consola
     * */
    void printOleada(){
        cout<<"=============================="<<endl;
        for(int i = 0; i<oleadaActual.size(); i ++){
            auto tmp1 = oleadaActual[i];
            auto tmp = Estudiantes->index(tmp1);
            if(tmp->getTipo() == 0){
                cout<< "Ogro" <<endl;
                cout << tmp1 <<endl;
            }
            else if(tmp->getTipo() == 1){
                cout<< "Elfos" <<endl;
                cout << tmp1 <<endl;
            }
            else if(tmp->getTipo() == 2){
                cout<< "Harpias" <<endl;
                cout << tmp1 <<endl;
            }
            else if(tmp->getTipo() == 3){
                cout<< "Mercenarios" <<endl;
                cout << tmp1 <<endl;
            }
        }
        cout<<"=============================="<<endl;
    }
    /**
     * @brief encuentreRutas es el méodo que ejecuta el backtracking o pathfinding a todos los estudiantes de la población
     * */

    void encuentreRutas(){
        int x =Estudiantes->lenght();
        int pathFinding = (x/100)*10;
        for(int i = 0; i <pathFinding; i++){
            hacerPathfinding(Estudiantes->index(i));
        }
        for(int a = pathFinding; a<Estudiantes->lenght(); a++){
            hacerBacktracking(Estudiantes->index(a));
        }
    }




};
/*                        Tipo Life Speed Arqueros Magos Artilleros Fuego
         Tipos
         Ogro 0
         Elfos Oscuros 1
         Harpias 2
         Mercenarios 3
         */

#endif //TECVSZOMBIES_JUEGO_H
