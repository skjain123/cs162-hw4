#include "gold.h"

#include <iostream>

using namespace std;

//Gold Implementation

string Gold::get_name() const {
    return this->name;
}

void Gold::set_name(string s) {
    this->name = s;
}

char Gold::get_symbol() const {
    if (!found) {
        return 'G';
    } else {
        return ' ';
    }
    
}

void Gold::exec(bool* kill_player, bool* has_gold, int* reverse_controls) {
    if (!found) {
        cout << "You picked up gold! Please escape to your original position to win the game!" << endl;
        *has_gold = true;
        found = true;
    }
    
}

void Gold::print_event_precept() {
    if (!found) {
        cout << "You see a glimmer nearby." << endl;
    }
}


Gold::Gold() : Event("GOLD") {
    this->name = "GOLD";
}

Gold::Gold(string s) : Event(s) {
    this->set_name(s);
    found = false;
    
}

Gold::~Gold() {
    //sdf
}