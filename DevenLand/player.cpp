#include "player.h"
#include <iostream>

Player::Player() : x(0), y(0), face(' ') {}
Player::Player(int x, int y, char f) : x(x), y(y), face(f) {}

void Player::move(direction direction, Tile grid[40][40]) {
	this->facing = direction;
	int oldX = x;
	int oldY = y;
	switch (direction) {
		case up:
			if (y == 0) return;
			if (!grid[y - 1][x].isBlocked) y--;
			break;
		case down:
			if (y == 39) return;
			if (!grid[y + 1][x].isBlocked) y++;
			break;
		case left:
			if (x == 0) return;
			if (!grid[y][x - 1].isBlocked) x--;
			break;
		case right:
			if (x == 39) return;
			if (!grid[y][x + 1].isBlocked) x++;
			break;
	}
	updateGrid(oldX, oldY, x, y, this->face);
}

bool Player::shoot(Player &player, Tile grid[40][40]) {
	//if (ammo == 0)
	//	return false;
	ammo--;
	int length = 0;
	int oldX, oldY, newX, newY;
	oldX = newX = x;
	oldY = newY = y;

	direction dir = this->facing;

	while (true) {
		oldX = newX;
		oldY = newY;
		length++;
		switch (dir) {
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

		if (grid[newY][newX].isBlocked) {
			updateGrid(oldX, oldY, newX, newY, ' ');
			grid[newY][newX].isBlocked = false;
			return false;
		} else if (player.y == newY && player.x == newX) {
			updateGrid(oldX, oldY, newX, newY, '_');
			return true;
		}

		Sleep(50);

		updateGrid(x, y, x, y, this->face);

		if (grid[newY][newX].item != nullptr)
			updateGrid(oldX, oldY, newX, newY, grid[newY][newX].item->icon);
		else if (oldY == y && oldX == x || grid[oldY][oldX].item != nullptr)
			updateGrid(newX, newY, newX, newY, '-');
		else 
			updateGrid(oldX, oldY, newX, newY, '-');
	}
}

void Player::updateGrid(int& oldX, int& oldY, int& newX, int& newY, const char &letter) {
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