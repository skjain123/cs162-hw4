#ifndef GOLD_H
#define GOLD_H 

#include "event.h"

//Gold Interface
class Gold : public Event {
private:
    bool found;

public:

    /**************************************************
 * Name: get_name()
 * Description: this function will return the event's name
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: do not change the name
 ***********************************************/
    string get_name() const override;

    /**************************************************
 * Name: set_name()
 * Description: this function will set the event's name
 * Parameters: a string that will be the new event's name
 * Pre-conditions: inputs a correct string
 * Post-conditions: none
 ***********************************************/
    void set_name(string) override;

/**************************************************
 * Name: get_symbol()
 * Description: this function will return the event's unique symbol to print in the grid
 * Parameters: none
 * Pre-conditions: used in debug mode
 * Post-conditions: outputs a correct char
 ***********************************************/
    char get_symbol() const override;

/**************************************************
 * Name: exec()
 * Description: this function will execute the event. ex: confuse the player when encountering gold
 * Parameters: bool* kill_player, bool* has_gold, int* reverse_controls
 * Pre-conditions: only used when the player moves into a room with a event
 * Post-conditions: outputs something, confuses player, or changes a boolean
 ***********************************************/
    void exec(bool*, bool*, int*) override;

/**************************************************
 * Name: print_event_precept()
 * Description: this function will execute the event
 * Parameters: bool* kill_player, bool* has_gold, int* reverse_controls
 * Pre-conditions: only used when the player moves into a room with a event
 * Post-conditions: outputs something, confuses player, or changes a boolean
 ***********************************************/
    void print_event_precept() override;

/**************************************************
 * Name: gold()
 * Description: constructor
 * Parameters: no
 * Pre-conditions: constructor
 * Post-conditions: sets name to "gold"
 ***********************************************/
    Gold();

/**************************************************
 * Name: gold()
 * Description: nondefault constructor
 * Parameters: string
 * Pre-conditions: constructor
 * Post-conditions: sets name to whatever gold
 ***********************************************/
    Gold(string);

/**************************************************
 * Name: gold()
 * Description: deconstructor
 * Parameters: no
 * Pre-conditions: deconstructor
 * Post-conditions: deletes dynamic memory
 ***********************************************/
    ~Gold();

};


#endif