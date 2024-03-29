//
// Created by isaac4918 on 1/11/19.
//

#ifndef CE_vs_Estudiantes_LIST_POSICIONES_H
#define CE_vs_Estudiantes_LIST_POSICIONES_H

#include <string>

#include <iostream>

using namespace std;

/*!

*Node that saves the data of the movie

*/



class Node {

public:

    int x, y;

    Node *next=NULL;

};

/*!

*Linked list to save all the movies get from the csv

*/

class List_Posiciones {



    /*!

   *Linked list method to display the linked list

   * Use tmp node to display each node until linked list is NULL



   */

public:

    void display(){

        Node* ptr=new Node;

        ptr = head;

        while (ptr != NULL) {

            std::cout<<"Pos X: "<< ptr->x<<"Pos Y: "<<ptr->y <<" "<<endl;

            ptr = ptr->next;

        }

    }



    /*!

*Linked list method to insert at the end of the list.

* Pass movie data and make a node that saves all of it's info

@param[in]  newdata   name of the movie to be inserted

@param[in]  year   year of the movie to be inserted

@param[in]  IMBDlink   IMDB link to search the url elements

@param[in]  director   director  of the movie to be inserted





*/



public:
    Node *head=NULL;

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



    void removeFirstNode()

    {



        // Move the head pointer to the next node

        Node* temp = head;

        head = head->next;



        delete temp;



    }





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

/**

* Move through the list to the last that is NULL

*/

        while (last->next != NULL)

            last = last->next;



        last->next = new_node;

        return;

    }

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

#endif //CE_vs_Estudiantes_LIST_POSICIONES_H
