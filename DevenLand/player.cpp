#include "player.h"
#include <iostream>

Player::Player() : x(0), y(0), face(' ') {}
Player::Player(int x, int y, char f) : x(x), y(y), face(f) {}

void Player::move(direction direction, bool grid[40][40]) {
	this->facing = direction;
	int oldX = x;
	int oldY = y;
	switch (direction) {
		case up:
			if (y == 0) return;
			if (grid[y - 1][x]) y--;
			break;
		case down:
			if (y == 39) return;
			if (grid[y + 1][x]) y++;
			break;
		case left:
			if (x == 0) return;
			if (grid[y][x - 1]) x--;
			break;
		case right:
			if (x == 39) return;
			if (grid[y][x + 1]) x++; 
			break;
	}
	updateGrid(oldX, oldY, x, y, this->face);
}

bool Player::shoot(Player &player, bool grid[40][40]) {
	int length = 1;
	int oldX, oldY, newX, newY;
	std::cout << "Facing: " << facing << std::endl;
	switch (facing) {
		case up:
			while (true) {
				length++;
				newY = y - length;
				if (player.y == newY && player.x == x)
					return true;
				if (newY == 0 || !grid[newY][x]) 
					return false;
				Sleep(10);
				updateGrid(x, newY + 1, x, newY, '-');
			}
			break;
		case down:
			while (true) {
				length++;
				int newY = y + length;
				if (player.y == newY && player.x == x)
					return true;
				if (newY == 39 || !grid[newY][x]) 
					return false;
				Sleep(10);
				updateGrid(x, newY - 1, x, newY, '-');
			}
			break;
		case left:
			while (true) {
				length++;
				int newX = x - length;
				if (player.y == y && player.x == newX) 
					return true;
				if (newX == 0 || !grid[y][newX]) 
					return false;
				Sleep(10);
				updateGrid(newX + 1, y, newX, y, '-');
			}
			break;
		case right:
			while (true) {
				length++;
				int newX = x + length;
				if (player.y == y && player.x == newX)
					return true;
				if (newX == 39 || !grid[y][newX])
					return false;
				Sleep(10);
				updateGrid(newX - 1, y, newX, y, '-');
			}
			break;
	}
}

void Player::updateGrid(int oldX, int oldY, int newX, int newY, const char &letter) {
	DWORD dw; // no idea
	COORD oldPosition = { getScreenXPos(oldX), oldY };
	COORD newPosition = { getScreenXPos(newX), newY };
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // no idea
	if (hStdOut == INVALID_HANDLE_VALUE) return;
	WriteConsoleOutputCharacter(hStdOut, " ", 1, oldPosition, &dw); // replace old pos with space
	WriteConsoleOutputCharacter(hStdOut, &letter, 1, newPosition, &dw); // set new pos with the face
}

int Player::getScreenXPos(int x) {
	return x * 2;
}