#ifndef EVENT_H
#define EVENT_H

#include "string"

using namespace std;

//Event Interface
//Note: this must be an abstract class!

class Event
{

protected:
	string name = "EVENT";

public:
/**************************************************
 * Name: get_name()
 * Description: this function will return the event's name
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: do not change the name
 ***********************************************/
	virtual string get_name() const = 0;

/**************************************************
 * Name: set_name()
 * Description: this function will set the event's name
 * Parameters: a string that will be the new event's name
 * Pre-conditions: inputs a correct string
 * Post-conditions: none
 ***********************************************/
    virtual void set_name(string) = 0;

/**************************************************
 * Name: get_symbol()
 * Description: this function will return the event's unique symbol to print in the grid
 * Parameters: none
 * Pre-conditions: used in debug mode
 * Post-conditions: outputs a correct char
 ***********************************************/
    virtual char get_symbol() const = 0;

/**************************************************
 * Name: exec()
 * Description: this function will execute the event. ex: confuse the player when encountering bats
 * Parameters: bool* kill_player, bool* has_gold, int* reverse_controls
 * Pre-conditions: only used when the player moves into a room with a event
 * Post-conditions: outputs something, confuses player, or changes a boolean
 ***********************************************/
    virtual void exec(bool*, bool*, int*) = 0;
    
/**************************************************
 * Name: print_event_precept()
 * Description: this function will execute the event
 * Parameters: bool* kill_player, bool* has_gold, int* reverse_controls
 * Pre-conditions: only used when the player moves into a room with a event
 * Post-conditions: outputs something, confuses player, or changes a boolean
 ***********************************************/
    virtual void print_event_precept() = 0;

/**************************************************
 * Name: Bat()
 * Description: constructor
 * Parameters: no
 * Pre-conditions: constructor
 * Post-conditions: sets name to "BAT"
 ***********************************************/
    Event();

/**************************************************
 * Name: Bat()
 * Description: nondefault constructor
 * Parameters: string
 * Pre-conditions: constructor
 * Post-conditions: sets name to whatever bat
 ***********************************************/
    Event(string);

/**************************************************
 * Name: Bat()
 * Description: deconstructor
 * Parameters: no
 * Pre-conditions: deconstructor
 * Post-conditions: deletes dynamic memory
 ***********************************************/
    virtual ~Event();

};
#endif