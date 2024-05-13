/******************************************************
** Program: main.cpp
** Author: Sunil Jain
** Date: 11/29/2023
** Description: Adventure text game through a 2D vector of rooms where you encounter various events
** Input: vector dimensions, debug mode activation, wasd movement, and f-firing
** Output: map of rooms and (debug mode) symbols for each events, coherent instructions
******************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;


int main()
{
	//set the random seed
	srand(time(NULL));
	
	int x_dim = 1;
	int y_dim = 1;
	bool debug = false;
	
	Game g;

	//get two inputs: size of the cave(wid and len)
	
	while (x_dim < 4 || 50 < x_dim) {
		cout << "Enter The x dimension of the screen (4-50): ";
		cin >> x_dim;
	}
	
	while (y_dim < 4 || 50 < y_dim) {
		cout << "Enter the y dimension of the screen (4-50): ";
		cin >> y_dim;
	}
	
	//get the 3rd input --> debug mode or not
	cout << "Debug mode? (yes-1, no-0): ";
	cin >> debug;

	//Play game
	g.play_game(x_dim, y_dim, debug);


	return 0;
}