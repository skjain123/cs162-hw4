#include "bats.h"

#include <iostream>

using namespace std;

//Bats Implementation

string Bat::get_name() const {
    return this->name;
}

void Bat::set_name(string s) {
    this->name = s;
}

char Bat::get_symbol() const {
    return 'B';
}

void Bat::exec(bool* kill_player, bool* has_gold, int* reverse_controls) {
    cout << "You stumble into bats and become disoriented." << endl;

    *reverse_controls = 5;
}

void Bat::print_event_precept() {
    cout << "You hear wings flapping." << endl;
}


Bat::Bat() : Event("BAT") {
    this->name = "BAT";
}

Bat::Bat(string s) : Event(s) {
    this->name = s;
}

Bat::~Bat() {
    //sdf
}