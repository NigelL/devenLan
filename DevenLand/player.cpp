#include "player.h"
#include <iostream>

// Default initialiser 
Player::Player() : x(0), y(0), face(' ') {}

// Initialiser with specified values
Player::Player(int x, int y, char f) : x(x), y(y), face(f) {}

// moves player in a specified direction in the grid
void Player::move(direction direction, Tile grid[40][40]) {
	// set the player's facing direction to specified direction
	this->facing = direction; 
	// saving a copy of the players old position
	int oldX = x;
	int oldY = y;

	// change the coordinate of the player based on where 
	switch (this->facing) {
		case up:
			// Do not move, if the player has reached the top.
			if (y == 0) return;
			// move if there is nothing blocking the player
			if (!grid[y - 1][x].isBlocked) y--;
			break;
		case down:
			// Do not move, if the player has reached the bottom.
			if (y == 39) return;
			// move if there is nothing blocking the player
			if (!grid[y + 1][x].isBlocked) y++;
			break;
		case left:
			// Do not move, if the player has reached the left.
			if (x == 0) return;
			// move if there is nothing blocking the player
			if (!grid[y][x - 1].isBlocked) x--;
			break;
		case right:
			// Do not move, if the player has reached the right.
			if (x == 39) return;
			// move if there is nothing blocking the player
			if (!grid[y][x + 1].isBlocked) x++;
			break;
	}
	// update the grid with the players old and new position
	updateGrid(oldX, oldY, x, y, this->face);
}

// shoot a player in the grid
bool Player::shoot(Player &player, Tile grid[40][40]) {
	// check if there is ammo left
	//if (ammo == 0)
	//	return false;
	// deduct ammo
	ammo--;

	// to save the old and new positions of the bullet
	int oldX, oldY, newX, newY;
	// initialise them with the player's current coordinates
	oldX = newX = x;
	oldY = newY = y;

	// make a copy of the direction that the player is facing.
	direction dir = this->facing;

	while (true) {
		// set the old position to the previous new position
		oldX = newX;
		oldY = newY;

		// check the direction travelling and change accordingly
		switch (dir) {
			case up:
				newY--;
				if (newY < 0) {
					// despawn bullet if it has passed the boarder
					updateGrid(oldX, oldY, newX, newY, ' ');
					return false;
				}
				break;
			case down:
				newY++;
				if (newY > 39) {
					// despawn bullet if it has passed the boarder
					updateGrid(oldX, oldY, newX, newY, ' ');
					return false;
				}
				break;
			case left:
				newX--;
				if (newX < 0) {
					// despawn bullet if it has passed the boarder
					updateGrid(oldX, oldY, newX, newY, ' ');
					return false;
				}
				break;
			case right:
				newX++;
				if (newX > 39) {
					// despawn bullet if it has passed the boarder
					updateGrid(oldX, oldY, newX, newY, ' ');
					return false;
				}
				break;
		}

		if (grid[newY][newX].isBlocked) {
			// despawn bullet if it has hit a wall
			updateGrid(oldX, oldY, newX, newY, ' ');
			// remove the wall as it has been destroyed
			grid[newY][newX].isBlocked = false;
			return false;
		} else if (player.y == newY && player.x == newX) {
			// this part is when the bullet has hit the player
			updateGrid(oldX, oldY, newX, newY, '_');
			return true;
		}

		updateGrid(x, y, x, y, this->face);

		// delay between frames of bullet
		Sleep(50);

		// check if there is item at the new position
		if (grid[newY][newX].item != nullptr)
			// do not animate bullet on this frame
			updateGrid(oldX, oldY, newX, newY, grid[newY][newX].item->icon);
		// check if player or item is behind bullet
		else if (oldY == y && oldX == x || grid[oldY][oldX].item != nullptr)
			// do not remove the previous tile.
			updateGrid(newX, newY, newX, newY, '-');
		else 
			// move bullet character to new position.
			updateGrid(oldX, oldY, newX, newY, '-');
	}
}

// updates grid based on old and new coordinate
void Player::updateGrid(int& oldX, int& oldY, int& newX, int& newY, const char &letter) {
	DWORD dw; // no idea
	COORD oldPosition = { getScreenXPos(oldX), oldY };
	COORD newPosition = { getScreenXPos(newX), newY };
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // no idea
	if (hStdOut == INVALID_HANDLE_VALUE) return;
	WriteConsoleOutputCharacter(hStdOut, " ", 1, oldPosition, &dw); // replace old pos with space
	WriteConsoleOutputCharacter(hStdOut, &letter, 1, newPosition, &dw); // set new pos with the face
}

// returns the true x position of the player in the console
int Player::getScreenXPos(int x) {
	return x * 2;
}