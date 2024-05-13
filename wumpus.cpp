#include "wumpus.h"

#include <iostream>

using namespace std;

//Wumpus Implementation

string Wumpus::get_name() const {
    return this->name;
}

void Wumpus::set_name(string s) {
    this->name = s;
}

char Wumpus::get_symbol() const {
    return 'W';
}

void Wumpus::exec(bool* kill_player, bool* has_gold, int* reverse_controls) {
    cout << "You found the Wumpus! You are dead." << endl;

    *kill_player = true;
}

void Wumpus::print_event_precept() {
    cout << "You smell a terrible stench." << endl;
}

Wumpus::Wumpus() : Event("WUMPUS") {
    this->name = "WUMPUS";
}

Wumpus::Wumpus(string s) : Event(s) {
    this->set_name(s);
}

Wumpus::~Wumpus() {
    //sdf
}