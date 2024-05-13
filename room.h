#ifndef ROOM_H
#define ROOM_H 

#include "event.h"

using namespace std;

//Room Interface
//Note: Each room may be empty or has an event (bat, gold, pit, or wumpus);
//		Use event polymorphically

class Room
{
private: 
    bool contain_player;
    Event* e;
	
public:
    
    /**************************************************
 * Name: set_contain_player
 * Description: sets the boolean contain_player
 * Parameters: boolean to set
 * Pre-conditions: player has to be in the room
 * Post-conditions: sets the variable correctly
 ***********************************************/
    void set_contain_player(const bool);

    /**************************************************
 * Name: set_event
 * Description: sets the event pointer in this room
 * Parameters: event pointer to a dynamic eveent
 * Pre-conditions: none
 * Post-conditions: updates the new event
 ***********************************************/
    void set_event(Event*);

/**************************************************
 * Name: check_event_name
 * Description: goes into the event and gets the event's symbol
 * Parameters: boolean to set
 * Pre-conditions: none
 * Post-conditions: gets the event's symbol
 ***********************************************/
    char check_event_name();

/**************************************************
 * Name: is_empty_room
 * Description: checks if the event is a nullptr or does not exist 
 * Parameters: none
 * Pre-conditions: room exists?
 * Post-conditions: used as a bool
 ***********************************************/
    bool is_empty_room();

    /**************************************************
 * Name: get_contain_player
 * Description: gets the boolean contain_player
 * Parameters: none
 * Pre-conditions: player has to be in the room
 * Post-conditions: sets the variable correctly
 ***********************************************/
    bool get_contain_player() const;

    /**************************************************
 * Name: get_event
 * Description: gets the event from the room
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: sets the variable correctly
 ***********************************************/
    Event* get_event();

/**************************************************
 * Name: execute_event
 * Description: goes into the event and calls the exec() function
 * Parameters: passes along bool* kill_player, bool* has_gold, int* reverse_controls
 * Pre-conditions: room exists
 * Post-conditions: calls it and outputs stuff 
 ***********************************************/
    void execute_event(bool*, bool*, int*);

/**************************************************
 * Name: Room
 * Description: constructor that initializes the variables
 * Parameters: none
 * Pre-conditions: create room
 * Post-conditions: create room
 ***********************************************/
    Room();

    /**************************************************
 * Name: ~Room
 * Description: deconstructor
 * Parameters: none
 * Pre-conditions: deconstruct dynamic variables
 * Post-conditions: deconstruct dynamic variables
 ***********************************************/
    ~Room();

};

#endif