#include "linked_list.h"
#include <cmath>
#include <iostream>
#include <string.h>

void nats::debug(string msg){

    cout << "DEBUG: " << msg << endl;

}

nats::LinkedList* nats::init(){

    debug("inizializzazione linked list");
    LinkedList* list = new LinkedList;
    list->head = NULL;
    return list;

};


bool nats::is_empty(LinkedList* ll){

    if(ll->head == NULL){
        debug("linked list vuota");
        return true;
    }else{
        debug("linked list piena");
        return false;
    }

}

              
void nats::add(LinkedList* ll, const char * label){    

    debug(string("aggiunta di un nuovo elemento: ") + label);
    Node* new_one = new Node;
    new_one->next = ll->head;
    new_one->label = label;
    
    ll->head = new_one;

}

int nats::size(LinkedList* ll){

    if(ll->head == NULL){
        int i = 0;
        return i;
    }else{
        Node* current = ll->head;
        int i = 0;
        if(current->next == NULL){
            i = 1;
        }else{
            while(current != NULL){
                i++;
                current = current->next;
            }
        }
        return i;
    }

} 

string nats::to_string(LinkedList* ll) {

    debug("stampa linked list");
    int i = nats::size(ll);
    if(i == 0){

        return string("Linked list vuota!");

    }else{
        Node* current = ll->head;
        string s;

        while(current != NULL){
            s = s + current->label + ", ";
            current = current->next;
        }

        int i = s.size();
        s.resize((i-2));
        return s;
    }

    
}


bool nats::search(LinkedList* ll, const char * label){
    
    Node* current = ll->head;

    while(current != NULL && current->label != label){
        current = current->next;
    }

    if(current == NULL){
        return false;
    }else{
        return true;
    }

}

      
const char* nats::pop(LinkedList* ll){
            
    debug("eliminazione dell'ultimo elemento");

    int i = nats::size(ll);

    if(i == 0){

        throw std::invalid_argument( "empty list!");

    }else{
        if(i == 1){
            
            const char* s = ll->head->label;
            ll->head = NULL;
            return s;

        }else{
            Node* current = ll->head;
            Node* precurrent;
            const char* s;

            while(current->next != NULL){
                precurrent = current;
                current = current->next;
            }

            precurrent->next = NULL;
            s = current->label;
            delete current;
            current->next = NULL;
            return s;
        }

    }

}

               
void nats::append(LinkedList* ll, const char* label){  
    debug(string("aggiunta elemento in fondo: ") + label);
    int i = nats::size(ll);
    if(i == 0){
        Node* new_last = new Node;
        new_last->label = label;
        new_last->next = NULL;
        ll->head = new_last;
    }else{
        Node* current = ll->head;
        Node* precurrent = ll->head;
        while(current != NULL){
            precurrent = current;
            current = current->next;
        }

        Node* new_last = new Node;
        new_last->label = label;
        new_last->next = NULL;
        precurrent->next = new_last;        
    }

}

void nats::remove(LinkedList* ll, const char * label){

    debug(string("rimozione elemento selezionato: ") + label);
    int i = nats::size(ll);
    if(i == 0){
        throw std::invalid_argument(" empty list! ");
    }else{
        Node* current = ll->head;
        Node* precurrent = ll->head;
        int count = 1;
        while(current != NULL && current->label != label){
            precurrent = current;
            current = current->next;
            count ++;
        }
        if(current == NULL){
            throw std::invalid_argument(" label is not found! ");
        }else{
            if(count == 1){
                delete ll->head;
                ll->head = current->next;
            }else{
                if(current->next != NULL){
                    precurrent->next = current->next;
                    delete current;
                    current->next = NULL;
                }else{
                    precurrent->next = NULL;
                    delete current;
                }
            }

        }
    }

}

void nats::insert(LinkedList* ll, int i, const char * e){

    int j = nats::size(ll);
    if(j == 0){
        Node* new_insert = new Node;
        new_insert->next = NULL;
        new_insert->label = e;
        ll->head = new_insert;
        return;
    }
    if(i > j){
        throw std::invalid_argument(" index out of bounds! ");
    }else{
        if(i == 0){
            Node* new_insert = new Node;
            new_insert->next = ll->head;
            new_insert->label = e;
            ll->head = new_insert;
        }else{
            if(i = j && j != 0){
                Node* current = ll->head;
                while(current->next != NULL){
                    current = current->next;
                }
                Node* new_insert = new Node;
                new_insert->next = NULL;
                new_insert->label = e;
                current->next = new_insert;
            }else{
                Node* current = ll->head;
                Node* precurrent;
                int count = 0;
                while(count != i){
                    precurrent = current;
                    count ++;
                    current = current->next;
                }
                Node* new_insert = new Node;
                new_insert->next = current->next;
                new_insert->label = e;
                current->next = new_insert;
            }
            
        }
    }
}
        


    /*
        Deletes all nodes in the chain    
        Careful about deletion order!

        (non basta un delete(ll) perché non terrebbe conto di tutti i nodi)
    */
void nats::destroy(LinkedList* ll){

    if(ll->head == NULL){       //Ho solo la testa
        
        delete ll->head;

    }else{
        Node* current = ll->head;

        while (current != NULL){
            Node* to_delete = current;
            current = current->next;
            delete to_delete;
            to_delete->next = NULL;
        } 

        
    }    
}





