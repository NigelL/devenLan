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
	if (ammo == 0)
		return false;
	ammo--;
	int length = 0;
	int oldX, oldY, newX, newY;
	oldX = newX = x;
	oldY = newY = y;
	while (true) {
		oldX = newX;
		oldY = newY;
		length++;
		switch (facing) {
			case up:
				newY = y - length;
				if (newY < 0) {
					updateGrid(oldX, oldY, newX, newY, ' ');
					return false;
				}
				break;
			case down:
				newY = y + length;
				if (newY > 39) {
					updateGrid(oldX, oldY, newX, newY, ' ');
					return false;
				}
				break;
			case left:
				newX = x - length;
				if (newX < 0) {
					updateGrid(oldX, oldY, newX, newY, ' ');
					return false;
				}
				break;
			case right:
				newX = x + length;
				if (newX > 39) {
					updateGrid(oldX, oldY, newX, newY, ' ');
					return false;
				}
				break;
		}

		if (!grid[newY][newX]) {
			updateGrid(oldX, oldY, newX, newY, ' ');
			grid[newY][newX] = true;
			return false;
		} else if (player.y == newY && player.x == newX) {
			updateGrid(oldX, oldY, newX, newY, '_');
			return true;
		}

		Sleep(50);

		if ((oldY == y && oldX != x) || (oldY != y && oldX == x))
			updateGrid(oldX, oldY, newX, newY, '-');
		else 
			updateGrid(newX, newY, newX, newY, '-');
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