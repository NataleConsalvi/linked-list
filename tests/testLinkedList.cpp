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

TEST_CASE("Verifica dimensione linked list (size)", "[linked_list]") {
    
    nats::LinkedList* ll = nats::init();

    int a = nats::size(ll);

    REQUIRE(a == 0);

    nats::add(ll, "a");
    nats::add(ll, "v");
    nats::add(ll, "o");
    nats::add(ll, "u");

    int b = nats::size(ll);

    REQUIRE(b == 4);

}

TEST_CASE("Verifica ricerca in linked list (search)", "[linked_list]") {
    
    nats::LinkedList* ll = nats::init();

    nats::add(ll, "a");
    nats::add(ll, "v");
    nats::add(ll, "o");
    nats::add(ll, "u");

    bool s = nats::search(ll,"a");

    REQUIRE(s == true);

    bool s1 = nats::search(ll,"e");

    REQUIRE(s1 == false);

}

TEST_CASE("Verifica eliminazione in coda (pop)", "[linked_list]") {
    
    nats::LinkedList* ll = nats::init();

    REQUIRE_THROWS_AS( nats::pop(ll), std::invalid_argument);

    nats::add(ll, "a");
    nats::add(ll, "v");
    nats::add(ll, "o");
    nats::add(ll, "u");

    const char* deleted = nats::pop(ll);
    REQUIRE(deleted == "a");

    const char* deleted2 = nats::pop(ll);
    REQUIRE(deleted2 == "v");

    string s = nats::to_string(ll);
    REQUIRE(s == "u, o");

}
