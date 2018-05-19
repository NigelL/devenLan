#ifndef PLAYER_H
#define PLAYER_H

#include "direction.h"

#include <windows.h>

struct Player {
	int x, y;
	int lives = 3;
	int ammo = 3;
	direction facing = right;
	const char face;

	Player();
	Player(int x, int y, char f);
	
	void move(direction direction, bool grid[40][40]);
	bool shoot(Player &player, bool grid[40][40]);

private:
	// updates grid based on old and new coord
	void updateGrid(int oldX, int oldY, int newX, int newY, const char &letter);
	// returns the true x position of the player in the console
	int getScreenXPos(int x);
};

#endif