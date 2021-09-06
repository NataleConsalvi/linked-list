#include "linked_list.h"
#include "catch2/catch2.hpp"

using namespace std;

/*
TEST_CASE("negative square_root should throw exception ", "[linked_list]") {
    

    // expects std::invalid_argument exception, if it is not thrown test fails        
    REQUIRE_THROWS_AS( square_root(-1.0), std::invalid_argument);

    REQUIRE(square_root(0.0) == Approx(0.0));


}
*/

TEST_CASE("Verifica inizializzazione (init)", "[linked_list]") {
    
    nats::LinkedList* ll = nats::init();

    REQUIRE(ll != NULL);

}

TEST_CASE("Verifica funzione is_empty", "[linked_list]") {
    
    nats::LinkedList* ll = nats::init();

    bool s = nats::is_empty(ll);
    REQUIRE(s == true);

    nats::add(ll, "a");
    bool s1 = nats::is_empty(ll);
    REQUIRE(s1 == false);

}

TEST_CASE("Verifica aggiunta in prima posizione (add)", "[linked_list]") {
    
    nats::LinkedList* ll = nats::init();

    nats::add(ll, "a");
    REQUIRE(ll->head->label == "a");

    nats::add(ll, "v");
    nats::add(ll, "o");
    nats::add(ll, "u");

    string s = nats::to_string(ll);
    REQUIRE(s == "u, o, v, a");

}

TEST_CASE("Verifica stampa (to_string)", "[linked_list]") {
    
    nats::LinkedList* ll = nats::init();

    nats::add(ll, "a");
    nats::add(ll, "v");
    nats::add(ll, "o");
    nats::add(ll, "u");

    string s = nats::to_string(ll);
    REQUIRE(s == "u, o, v, a");

}