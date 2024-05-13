#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream> 
#include "room.h"

using namespace std;

//Game interface 
class Game
{
private:
	
	//declare a 2D vector of Room objects:

	//other member variables:
	int x_dim; 			//length of the board
	int y_dim;  			//width of the board
	int num_arrows; 		//keep track of number of errors remaining
	bool debug_view;		//debug mode or not

	int initial_player_x;
	int initial_player_y;
	int player_x;
	int player_y;

	int wumpus_x;
	int wumpus_y;

	vector<vector<Room> > room_arr;

	bool kill_player;
	bool has_gold;
	bool wumpus_dead;
	int reverse_controls;

	//feel free to add more variables...

public:

	//suggested functions:
	Game();
	~Game();
	
	/**************************************************
 * Name: randomly_insert_events
 * Description: generates random places in a 2d array then inserts an event into it
 * Parameters: none
 * Pre-conditions: in the setup
 * Post-conditions: inserts events
 ***********************************************/
	void randomly_insert_events();

	/**************************************************
 * Name: set_up
 * Description: sets up the 2d vector and generates random events, and all that
 * Parameters: the dimensions of the 2d vector
 * Pre-conditions: only in the play game function
 * Post-conditions: sets everything up
 ***********************************************/
	void set_up(int, int);

	/**************************************************
 * Name: create board
 * Description: creates the 2d vector
 * Parameters: nothing
 * Pre-conditions: in setup
 * Post-conditions: creates room 2d vector
 ***********************************************/
	void create_board();

/**************************************************
 * Name: check_precepts and print_precepts
 * Description: checks the rooms adjacent to the player and sees events and their precepts 
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: makes sure to not check outside the vector
 ***********************************************/
	void check_precepts();
	void print_precepts(char);

/**************************************************
 * Name: display_game
 * Description: handles everything displayed to the screen
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: prints 2d vector correctly
 ***********************************************/
	void display_game() const;

	/**************************************************
 * Name: check_win
 * Description: checks if player is killed or if the wumpus is killed or if the player has gold and returned to original spot
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: none
 ***********************************************/
	bool check_win() const;

	/**************************************************
 * Name: get_dir
 * Description: gets user input for the direction
 * Parameters: none
 * Pre-conditions: used appropriately with fire and moving
 * Post-conditions: gets only designated chars
 ***********************************************/
	char get_dir();

	/**************************************************
 * Name: wumpus_move
 * Description: if arrow misses, 75% chance to move the wumpus around the grid
 * Parameters: none
 * Pre-conditions: if an arrow misses
 * Post-conditions: handles memory correctly
 ***********************************************/
	void wumpus_move();

	/**************************************************
 * Name: fire_arrow and all up down left right
 * Description: sees the next three spaces in the desired direction and checks for the wumpus within the grid
 * Parameters: none
 * Pre-conditions: when player inputs f
 * Post-conditions: doesnt go out of scope
 ***********************************************/
	void fire_arrow();
	void fire_arrow_up();
	void fire_arrow_down();
	void fire_arrow_left();
	void fire_arrow_right();

	/**************************************************
 * Name: move and up down left right
 * Description: gets a character in and calls up down left right based on it
 * Parameters: character
 * Pre-conditions: gets character from player
 * Post-conditions: only accepts appropriate chars
 ***********************************************/
	void move_up();
	void move_down();
	void move_left();
	void move_right();
	void move(char);

	/**************************************************
 * Name: get_input
 * Description: gets input from player and prints options
 * Parameters: none
 * Pre-conditions: every term call this
 * Post-conditions: accepts only certain chars
 ***********************************************/
	char get_input();

/**************************************************
 * Name: play_game
 * Description: sets up stuff
 * Parameters: passes dim of grid and the debug boolean
 * Pre-conditions: only used from main.cpp
 * Post-conditions: none
 ***********************************************/
	void play_game(int, int, bool);

/**************************************************
 * Name: print_debug_symbols
 * Description: if debug then print the event symbols
 * Parameters: current room that it is in
 * Pre-conditions: only used when debug
 * Post-conditions: prints properly?
 ***********************************************/
	void print_debug_symbols(Room) const;

	/**************************************************
 * Name: bat effect
 * Description: if the player is disoriented then return either -1 if not then 1 (affects move and fire funcs)
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: none
 ***********************************************/
	int bat_effect();

};
#endif