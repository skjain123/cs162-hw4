#include <iostream>
#include "room.h"
#include "bats.h"

using namespace std;

//Room Implementation
void Room::set_contain_player(const bool b) {
    this->contain_player = b;
}

bool Room::get_contain_player() const {
    return this->contain_player;
}

void Room::set_event(Event* event) {
    this->e = event;
}

Event* Room::get_event() {
    return this->e;
}

char Room::check_event_name() {
    if (e != nullptr) {
        return e->get_symbol();
    }
    
    return ' ';
}

bool Room::is_empty_room() {
    return (this->e->get_name() == "NULL");
}

void Room::execute_event(bool* kill_player, bool* has_gold, int* reverse_controls) {
    if (e != nullptr) {
        e->exec(kill_player, has_gold, reverse_controls);
    }
    
}

Room::Room() {
    this->e = nullptr;
}

Room::~Room() {
    //sdf
}