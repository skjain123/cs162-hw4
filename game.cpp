#include "game.h"
#include "gold.h"
#include "stalactites.h"
#include "bats.h"
#include "wumpus.h"

#include <iostream>
#include <cstdlib>

using namespace std;

//Game Implementation

Game::Game(){
	//Game constructor
	//Your code here:

	
	kill_player = false;
	has_gold = false;
	wumpus_dead = false;
	reverse_controls = 0;

}

Game::~Game(){
	for (int i = 0; i < this->y_dim; ++i) {
		for (int j = 0; j < this->x_dim; ++j) {
			Event* e_del = room_arr[i][j].get_event();
			if (e_del != nullptr) {
				delete e_del;
			}
			room_arr[i][j].set_event(nullptr);
		}
	}
}

void Game::create_board() {
	room_arr.clear();
	for (int i = 0; i < y_dim; i++) {
		vector<Room> row_vec;
		for (int j = 0; j < x_dim; j++) {
			row_vec.push_back(Room());
		}
		cout << endl;
		this->room_arr.push_back(row_vec);
	}
}

void Game::randomly_insert_events() {
	// randomly insert events (2 bats, 2 stalactites, 1 wumpus, 1 gold)
	int bat = 2;
	int stalactites = 2;
	int wumpus = 1;
	int gold = 1;
	int player = 1;

	int sum = bat+stalactites+wumpus+gold+player;

	while (sum > 0) {
		int rand_row = rand() % this->y_dim;
		int rand_col = rand() % this->x_dim;
		if (room_arr[rand_row][rand_col].get_event() == nullptr) {
			if (bat > 0) {
				room_arr[rand_row][rand_col].set_event(new Bat("BAT")); bat--;
			} else if (stalactites > 0) {
				room_arr[rand_row][rand_col].set_event(new Stalactite("STAL")); stalactites--;
			} else if (wumpus > 0) {
				room_arr[rand_row][rand_col].set_event(new Wumpus("WUMPUS"));
				wumpus_x = rand_row; wumpus_y = rand_col; wumpus--;
			} else if (gold > 0) {
				room_arr[rand_row][rand_col].set_event(new Gold("GOLD")); gold--;
			} else if (player > 0) {
				initial_player_x = rand_row; initial_player_y = rand_col;
				player_x = rand_row; player_y = rand_col; player--;
			}
		}
		sum = bat+stalactites+wumpus+gold+player;
	}
}

void Game::set_up(int x, int y){
	//set up the game
	this->x_dim = x;
	this->y_dim = y;

	create_board();

	this->num_arrows = 3; 	//start with 3 arrows

	randomly_insert_events();	
}

void Game::print_precepts(char e) {
	if (e == 'B') {
		cout << "You hear wings flapping." << endl;
	} else if (e == 'G') {
		cout <<  "You see a glimmer nearby." << endl;
	} else if (e == 'S') {
		cout << "You hear water dripping." << endl;
	} else if (e == 'W') {
		cout << "You smell a terrible stench." << endl;
	} else cout << endl;
}

void Game::check_precepts() {
	if (player_x > 0) {
		print_precepts(room_arr[player_x-1][player_y].check_event_name());
	} else cout << endl;

	if (player_x < y_dim-1) {
		print_precepts(room_arr[player_x+1][player_y].check_event_name());
	} else cout << endl;

	if (player_y > 0) {
		print_precepts(room_arr[player_x][player_y-1].check_event_name());
	} else cout << endl;

	if (player_y < x_dim-1) {
		print_precepts(room_arr[player_x][player_y+1].check_event_name());
	} else cout << endl;
}

//Note: you need to modify this function
void Game::display_game() const{
	cout << endl << endl;

	cout << "Arrows remaining: " << this->num_arrows << endl;
	
	string line = "";
	for (int i = 0; i < this->x_dim; ++i) line += "-----";

	for (int i = 0; i < this->y_dim; ++i) {
		cout << line << endl;
		for (int j = 0; j < this->x_dim; ++j) {
			cout << " ";
			if (i == this->player_x && j == this->player_y) {
				cout << "* ||";;
			} else {
				if (this->debug_view) {
					this->print_debug_symbols(this->room_arr[i][j]);
					cout << " ||";
				} else {
					cout << "  ||";
				}
			}
		}
		cout << endl;
	}
	cout << line << endl;

	//example output (when finished): 
	// --------------------
	//  B || G || B ||   ||
	// --------------------
	//    || W ||   || S ||
	// --------------------   
	//    ||   ||   || S ||
	// --------------------   
	// *  ||   ||   ||   ||
	// --------------------
}

void Game::print_debug_symbols(Room r) const {
	if (r.get_event() != nullptr) {
		cout << r.check_event_name();
	} else {
		cout << " ";
	}
}

bool Game::check_win() const{
	//check if game over/win
	//Your code here:

	if (has_gold == true && initial_player_x == player_x && initial_player_y == player_y) {
		cout << "You won by finding the gold and returning to your original position!" << endl;
		return true;
	}

	if (kill_player) {
		cout << "You got killed!" << endl << "You Lose!" << endl;
		return true;
	}

	if (wumpus_dead) {
		cout << "You killed the Wumpus! You Win!" << endl;
		return true;
	}

	return false;
}

int Game::bat_effect() {
	if (reverse_controls > 0) {
		return -1;
	} else {
		return 1;
	}

}

void Game::move_up() {
	//move player up
	//Your code here:

	if (player_x > 0) {
		player_x--;
	}
	
	reverse_controls--;

	return;

}

void Game::move_down() {
	//move player down
	//Your code here:

	if (player_x < y_dim-1) {
		player_x++;
	}
	
	reverse_controls--;

	return;
}

void Game::move_left() {
	//move player left
	//Your code here:

	if (player_y > 0) {
		player_y--;
	}
	
	reverse_controls--;

	return;

}

void Game::move_right() {
	//move player right
	//Your code here:

	if (player_y < x_dim-1) {
		player_y++;
	}
	
	reverse_controls--;

	return;
}

char Game::get_dir(){
	//get direction of arrow:
	char dir;
	//Note: error checking is needed!! 
	//Your code here:
	cout << "Fire an arrow...." << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	

	cout << "Enter direction: " << endl;
	cin >> dir;
	cin.ignore(256, '\n');

	return dir;
}

void Game::wumpus_move(){
	//after a missed arrow, 75% chance that the wumpus is moved to a different room

	//How to get 75%? 
	//Hint: generate a random number from 0-3, if the number is not 0, then move

	//Your code here:
	
	if ((rand() % 4) != 0) {
		Event* del_e = room_arr[wumpus_x][wumpus_y].get_event();

		if (del_e != nullptr) {
			delete del_e;
		}

		room_arr[wumpus_x][wumpus_y].set_event(nullptr);
		int rand_x = rand() % y_dim;
		int rand_y = rand() % x_dim;

		if (room_arr[rand_x][rand_y].get_event() == nullptr) {
			room_arr[rand_x][rand_y].set_event(new Wumpus("WUMPUS"));
		}
		
	}
	
	return;
}

void Game::fire_arrow_up() {
	for (int i = 0; i < 3; i++) {
		if (player_x-(i+1) >= 0) {
			if (room_arr[player_x-(i+1)][player_y].check_event_name() == 'W') {
				wumpus_dead = true;
			} else {
				wumpus_move();
			}
		}
	}

	num_arrows--;
}

void Game::fire_arrow_down() {
	for (int i = 0; i < 3; i++) {
		if (player_x+(i+1) <= y_dim-1) {
			if (room_arr[player_x+(i+1)][player_y].check_event_name() == 'W') {
				wumpus_dead = true;
			} else {
				wumpus_move();
			}
		}
	}
	num_arrows--;
}

void Game::fire_arrow_left() {
	for (int i = 0; i < 3; i++) {
		if (player_y-(i+1) >= 0) {
			if (room_arr[player_x][player_y-(i+1)].check_event_name() == 'W') {
				wumpus_dead = true;
			} else {
				wumpus_move();
			}
		}
	}
	num_arrows--;
}

void Game::fire_arrow_right() {
	for (int i = 0; i < 3; i++) {
		if (player_x + (i+1) <= x_dim-1) {
			if (room_arr[player_x][player_y+(i+1)].check_event_name() == 'W') {
				wumpus_dead = true;
			} else {
				wumpus_move();
			}
		}
	}
	num_arrows--;
}

void Game::fire_arrow(){
	
	if (num_arrows == 0) {
		cout << "No arrows Left!" << endl << endl;
		return;
	}

	char dir = get_dir();
	
	if (dir == 'w') {
		if (bat_effect() == 1) {fire_arrow_up();} else {fire_arrow_down();}
	} else if (dir == 'a') {
		if (bat_effect() == 1) {fire_arrow_left();} else {fire_arrow_right();}
	} else if (dir == 's') {
		if (bat_effect() == 1) {fire_arrow_down();} else {fire_arrow_up();}
	} else if (dir == 'd') {
		if (bat_effect() == 1) {fire_arrow_right();} else {fire_arrow_left();}
	}

	return;

}

void Game::move(char c) {
	// Handle player's action: move or fire an arrow
	if (c == 'f'){
		Game::fire_arrow();
		return;
	}

	switch(c){
		case 'w':
			if (bat_effect() == 1) {Game::move_up();} else {Game::move_down();}
			break;
		case 'a':
			if (bat_effect() == 1) {Game::move_left();} else {Game::move_right();}
			break;
		case 's':
			if (bat_effect() == 1) {Game::move_down();} else {Game::move_up();}
			break;
		case 'd':
			if (bat_effect() == 1) {Game::move_right();} else {Game::move_left();}
			break;
	}
}

char Game::get_input(){
	//get action, move direction or firing an arrow

	//Note: error checking is needed!!
	//Your code here:
	char c;

	cout << endl << endl << "Player move..." << endl << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	cout << "f-fire an arrow" << endl;

	cout << "Enter input: " << endl;
	cin >> c;
	cin.ignore(256, '\n');

	
	return c;
}

//Note: you need to modify this function
void Game::play_game(int x, int y, bool d){

	Game::set_up(x, y);
	this->debug_view = d;
	

	char input;

	reverse_controls = 0;


	
	do {
		//print game board
		Game::display_game();

		//display percerts around player's location
		Game::check_precepts();

		//Your code here:

		//Player move...
		//1. get input
		input = Game::get_input();

		//2. move player
		Game::move(input);

		//3. may or may not encounter events
		this->room_arr[player_x][player_y].execute_event(&kill_player, &has_gold, &reverse_controls);

	} while (!Game::check_win());
	
	
	return;

}