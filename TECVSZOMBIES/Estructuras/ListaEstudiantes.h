/**
 * @file ListaEstudiantes.h
 * @version 1.0
 * @date 01/11/2019
 * @author Allan Calderón
 * @title Lista de estudiantes
 * @brief Estructura de datos para alamacenar estudiantes
 * */


#ifndef TECVSZOMBIES_LISTAESTUDIANTES_H
#define TECVSZOMBIES_LISTAESTUDIANTES_H



#include <iostream>
#include "../Estudiantes/Estudiante.h"

using namespace std;

/**
 * @brief Esta clase es una estructura de datos de tipo lista enlazada que está diseñada para almacenar los objetos estudiantes
 * que son los que conforman sus nodos
 * */

class ListaEstudiantes{
private:
    Estudiante *head = nullptr;
    int len;
public:

    /**
     * @brief Constructor de la clase que inicializa el head y el largo de la lista
     * */
    ListaEstudiantes(){
        len = 0;
        head = nullptr;
    }

    /**
     * @brief Método insert que funciona para ingresar una pelicula a la lista enviandola al final de la lista
     * @param peli_es el nodo de tipo pelicula que será insertado en la lista
     * */
    void insert(Estudiante *student){
        if(head== nullptr){
            head = student;
            len += 1;
        }
        else if(head != nullptr){
            Estudiante *tmp = head;
            while(tmp->next != nullptr){
                tmp =tmp->next;
            }
            tmp->next = student;
            len += 1;
        }
    }

    /**
     * @brief Método que permite imprimir información de la lista en consola, funcional para la prueba de otros métodos
     * */

    void printL(){
        Estudiante *tmp = head;
        while (tmp != nullptr){
            if(tmp->getTipo() == 0){
                cout<< "Ogro" <<endl;
            }
            else if(tmp->getTipo() == 1){
                cout<< "Elfos" <<endl;
            }
            else if(tmp->getTipo() == 2){
                cout<< "Harpias" <<endl;
            }
            else if(tmp->getTipo() == 3){
                cout<< "Mercenarios" <<endl;
            }
            tmp = tmp->next;
        }

    }

    /**
     * @brief Método que permite borrar el primer elemento de la lista
     * */

    void deleFirst(){
        if(head== nullptr){
            cerr << "No hay elementos en la Lista" << endl;
        }
        else if(head != nullptr){
            if(len == 1){
                head = nullptr;
                len --;
            }
            else if(len>1){
                Estudiante *tmp1 = head->next;
                head = nullptr;
                head = tmp1;
                len --;
            }

        }
    }

    /**
     * @brief Método que permite eliminar el ultimo elemento de la lista
     * */

    void deleLast(){
        if(head== nullptr){
            cerr << "No hay elementos en la Lista" << endl;
        }
        else if(this->len == 1){
            this->head = nullptr;
            len --;
        }
        else{
            Estudiante *tmp = this->head;
            while(tmp->next->next != nullptr){
                tmp = tmp->next;
            }
            tmp->next= nullptr;
            this->len --;
        }

    }
    /**
     * @brief Método que permite acceder a los nodos de la lista por una posición
     *
     * @param pos_es el numero de la posición a la que queremos acceder de la lista
     * */

    Estudiante * index(int pos){
        Estudiante *tmp = head;
        int i = 0;
        while(i != pos){
            tmp = tmp->next;
            i++;
        }
        return tmp;
    }
    int lenght(){
        return len;
    }
};


#endif //TECVSZOMBIES_LISTAESTUDIANTES_H
