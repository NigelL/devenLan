#ifndef PLAYER_H
#define PLAYER_H

#include "direction.h"
#include "Tile.h"

#include <windows.h>

struct Player {
	// stores coordinates of player
	int x, y;

	int lives = 3;
	int ammo = 3;

	// states which direction the player is currently facing
	direction facing = right;

	// stores the face of the character
	const char face;

	// Default initialiser 
	Player();

	// Initialiser with specified values
	Player(int x, int y, char f);
	
	// moves player in a specified direction in the grid
	void move(direction direction, Tile grid[40][40]);

	// shoot a player in the grid
	bool shoot(Player &player, Tile grid[40][40]);

private:
	// updates grid based on old and new coordinate
	void updateGrid(int& oldX, int& oldY, int& newX, int& newY, const char &letter);

	// returns the true x position of the player in the consolei 
	int getScreenXPos(int x);
};

#endif