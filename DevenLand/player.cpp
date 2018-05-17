#include "player.h"
#include <iostream>

Player::Player() : x(0), y(0), face(' ') {}
Player::Player(int x, int y, char f) : x(x), y(y), face(f) {}

void Player::move(direction direction, bool grid[40][40]) {
	this->facing = direction;
	switch (direction) {
		case up:
			if (y == 0) return;
			if (grid[y - 1][x]) {
				y--;
				updateGrid(x, y + 1, x, y);
			}
			break;
		case down:
			if (y == 39) return;
			if (grid[y + 1][x]) {
				y++;
				updateGrid(x, y - 1, x, y);
			}
			break;
		case left:
			if (x == 0) return;
			if (grid[y][x - 1]) {
				x--;
				updateGrid(x + 1, y, x, y);
			}
			break;
		case right:
			if (x == 39) return;
			if (grid[y][x + 1]) {
				x++; 
				updateGrid(x - 1, y, x, y);
			}
			break;
	}
}

bool Player::shoot(Player &player, bool grid[40][40]) {
	int length = 0;
	std::cout << "Facing: " << facing << std::endl;
	switch (facing) {
		case up:
			while (true) {
				length++;
				if (player.y == y - length && player.x == x)
					return true;
				if (y - length == 0 || !grid[y - length][x]) 
					return false;
			}
			break;
		case down:
			while (true) {
				length++;
				if (player.y == y + length && player.x == x)
					return true;
				if (y + length == 39 || !grid[y + length][x]) 
					return false;
			}
			break;
		case left:
			while (true) {
				length++;
				if (player.y == y && player.x == x - length) 
					return true;
				if (x - length == 0 || !grid[y][x - length]) 
					return false;
			}
			break;
		case right:
			while (true) {
				length++;
				if (player.y == y && player.x == x + length)
					return true;
				if (x + length == 39 || !grid[y][x + length])
					return false;
			}
			break;
	}
}

void Player::updateGrid(int oldX, int oldY, int newX, int newY) {
	DWORD dw; // no idea
	COORD oldPosition = { getScreenXPos(oldX), oldY };
	COORD newPosition = { getScreenXPos(newX), newY };
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // no idea
	if (hStdOut == INVALID_HANDLE_VALUE) return;
	WriteConsoleOutputCharacter(hStdOut, " ", 1, oldPosition, &dw); // replace old pos with space
	WriteConsoleOutputCharacter(hStdOut, &this->face, 1, newPosition, &dw); // set new pos with the face
}

int Player::getScreenXPos(int x) {
	return x * 2;
}