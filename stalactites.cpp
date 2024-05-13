#include "stalactites.h"

#include <iostream>

using namespace std;

//Stalactites Implementation

string Stalactite::get_name() const {
    return this->name;
}

void Stalactite::set_name(string s) {
    this->name = s;
}

char Stalactite::get_symbol() const {
    return 'S';
}

void Stalactite::exec(bool* kill_player, bool* has_gold, int* reverse_controls) {
    if (rand() % 2) {
        *kill_player = true;
        cout << "A Stalactite fell on you! You are dead." << endl;
    }
    
}

void Stalactite::print_event_precept() {
    cout << "You hear water dripping." << endl;
}

Stalactite::Stalactite() : Event("STAL") {
    this->name = "STAL";
}

Stalactite::Stalactite(string s) : Event(s) {
    this->set_name(s);
}

Stalactite::~Stalactite() {
    //sdf
}