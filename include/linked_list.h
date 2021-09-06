#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <string.h>
#include <stdexcept>
#include <cmath>


using namespace std;

namespace nats {

    /*
        White a message (string) with "DEBUG: msg".
    */
    void debug(string msg);


    /*
        A Node of an LinkedList. 
        Nodes are never returned by functions
    */
    struct Node {
            
        const char* label = NULL;
        Node* next = NULL;
    };


    /*
        Holds only one pointer to the first node.
    */
    struct LinkedList {

        Node* head = NULL;
    };


    /*
        Returns a NEW empty LinkedList.
    */
    LinkedList* init();

    /*
        Return true if the list is empty, false otherwise.      
    */
    bool is_empty(LinkedList* ll);

    /*
        Adds item at the beginning of the list.
    */                
    void add(LinkedList* ll, const char * label);


    /*
        Print the labels of the linked list.
    */
    string to_string(LinkedList* ll);

    /*
        Returns the size of the list.
    */
    int size(LinkedList* ll); 

    /*
        Returns true if label is present in list, false otherwise.
    */
    bool search(LinkedList* ll, const char * label);


    /*
        Removes the last item of the list, and returns its label.

        - If the list is empty, write

            throw std::invalid_argument( "empty list!" );
    */        
    const char* pop(LinkedList* ll);


    /*
        Appends label to the end of the list.
    */                
    void append(LinkedList* ll, const char* label);


    /*
        Remove first occurrence of item from the list.

        - If label is not found, throw std::invalid_argument                    
    */
    void remove(LinkedList* ll, const char * label);


    /*
        Insert an item at a given position. 

        - if index is out of bounds, throw std::invalid_argument   
    */
    void insert(LinkedList* ll, int i, const char * e);


    /*
        Deletes all nodes in the chain.
    */
    void destroy(LinkedList* ll);

}



#endif