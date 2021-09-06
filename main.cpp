#include <iostream>

#include "linked_list.h"

using namespace std;

int main(int, char**) {

    nats::LinkedList* ll = nats::init();

    nats::add(ll, "a");
    nats::add(ll, "b");
    nats::add(ll, "c");

    cout << nats::to_string(ll) << endl;

    
    cout << "size:" << nats::size(ll) << endl;

    nats::add(ll, "d");

    cout << nats::to_string(ll) << endl;

    cout << "size:" << nats::size(ll) << endl;

    
    
    cout << "search(ll,\"a\"): " << (nats::search(ll, "a") ? "true" : "false") << endl;

    cout << "search(ll,\"z\"): " << (nats::search(ll, "z")  ? "true" : "false") << endl;

    cout << "search(ll,\"d\"): " << (nats::search(ll, "d")  ? "true" : "false") << endl;

    
    cout << nats::pop(ll) << endl;    
    
    cout << nats::to_string(ll) << endl;


    cout << nats::pop(ll) << endl;    

    cout << nats::to_string(ll) << endl;

    cout << nats::pop(ll) << endl;    
    
    cout << nats::to_string(ll) << endl;

    cout << nats::pop(ll) << endl;    
    
    cout << nats::to_string(ll) << endl;

    nats::append(ll, "f");
    cout << nats::to_string(ll) << endl;

    nats::append(ll, "s");
    cout << nats::to_string(ll) << endl;

    nats::add(ll, "a");
    nats::add(ll, "b");
    nats::add(ll, "c");

    cout << nats::to_string(ll) << endl;

    // to test exception
    //cout << nats::pop(ll) << endl;

    nats::append(ll, "p");
    cout << nats::to_string(ll) << endl;

    nats::remove(ll, "c");
    cout << nats::to_string(ll) << endl;

    nats::remove(ll, "p");
    cout << nats::to_string(ll) << endl;

    nats::remove(ll, "f");
    cout << nats::to_string(ll) << endl;

    // to test exception
    /*
    nats::remove(ll, "o");
    cout << nats::to_string(ll) << endl;
    */

    nats::insert(ll, 0, "r");
    cout << nats::to_string(ll) << endl;

    nats::insert(ll, 3, "v");
    cout << nats::to_string(ll) << endl;

    // to test exception
    /*
    nats::insert(ll, 100, "0");
    cout << nats::to_string(ll) << endl;
    */
    
    nats::destroy(ll);

    cout << "destroyed"  << endl;  


} 