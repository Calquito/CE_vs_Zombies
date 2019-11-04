/**
 * @file List_Posiciones.h
 * @version 1.0
 * @date 01/11/2019
 * @author Isaac Araya
 * @title Lista de posiciones
 * @brief Estructura de datos para alamacenar posiciones
 * */


#ifndef TECVSZOMBIES_LIST_POSICIONES_H
#define TECVSZOMBIES_LIST_POSICIONES_H

#include <string>

#include <iostream>

using namespace std;

/**
*
*@brief Nodo que almacena las posiciones x y y
*
**/



class Node {

public:

    int x, y;

    Node *next=NULL;

};

/**
*@brief Linked list que almacena las posiciones
**/

class List_Posiciones {


public:

    /**
     * @brief display es un método para mostrar las posiciones
     * */

    void display(){

        Node* ptr=new Node;

        ptr = head;

        while (ptr != NULL) {

            std::cout<<"Pos X: "<< ptr->x<<"Pos Y: "<<ptr->y <<" "<<endl;

            ptr = ptr->next;

        }

    }



public:
    Node *head=NULL;

    /**
     * @brief removeLastNode es un método para quitar la ultima posicion de la lista
     * */

    Node* removeLastNode()

    {

        if (head == NULL)

            return NULL;



        if (head->next == NULL) {

            delete head;

            return NULL;

        }



        // Find the second last node

        Node* second_last = head;

        while (second_last->next->next != NULL)

            second_last = second_last->next;



        // Delete last node

        delete (second_last->next);



        // Change next of second last

        second_last->next = NULL;



        return head;

    }


    /**
     * @brief removeFirstNode es un método que permite quitar la primera posicion de la lista
     * */
    void removeFirstNode()

    {



        // Move the head pointer to the next node

        Node* temp = head;

        head = head->next;



        delete temp;



    }




    /**
     * @brief insert es un método para insertar elementos a la lista
     * @param x es la posicion x del nuevo elemento
     * @param y es la posicion y del nuevo elemento
     * */

    void insert(int x, int y) {

        Node* new_node=new Node;

        Node* last=head;

        new_node->x = x;

        new_node->y = y;

        new_node->next = NULL;





        if (head == NULL)

        {

            head = new_node;

            return;

        }


        while (last->next != NULL)

            last = last->next;



        last->next = new_node;

        return;

    }

    /**
     * @brief GetNth es un método que retorna el nodo de la lista en la posicion determinada
     * @param index es el indice que se buscará en la lista
     * */

    Node* GetNth( int index) {
        if (head != NULL) {

            Node *current = head;

            // the index of the
            // node we're currently
            // looking at
            int count = 0;
            while (current != NULL) {
                if (count == index)
                    return (current);
                count++;
                current = current->next;
            }
        }

    }

    /**
     * @brief getsize es un método que devuelve el tamaño de la lista
     * */

    int getsize() {
        int size = 0;
        Node *ptr = new Node;
        ptr = head;
        while (ptr != NULL) {
            ptr = ptr->next;
            size = size + 1;
        }
        return size;
    }

};

#endif //TECVSZOMBIES_LIST_POSICIONES_H
