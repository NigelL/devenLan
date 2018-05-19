#include "player.h"

#include <iostream>
#include <string>
#include <Windows.h>

void GenerateMaze(bool baseGrid[40][40]);
// false - wall. true - free
bool grid[40][40]; // y, x

Player *player1 = new Player(0, 0, 'X');
Player *player2 = new Player(39, 39, 'O');

void loadGrid() {
	// clear console
	 system("cls");
	// iterate through grid array
	for (int y = 0; y < 40; y++) {
		std::string line = "";
		for (int x = 0; x < 40; x++) {
			// check if this is player 1's location
			if (player1->x == x && player1->y == y)
				line += player1->face;
			else if (player2->x == x && player2->y == y)
				line += player2->face;
			else // check if this is a wall
				line += (grid[y][x] ? " " : "#");
			line += " ";
		}
		std::cout << line << std::endl;
	}
}

std::string spaces(int x) {
	std::string value = "";
	for (int i = 0; i < x; i++)
		value += " ";
	return value;
}

void displayStats() {
	std::cout << std::endl;

	std::cout << "Player 1" << spaces(80 - 16) << "Player 2" << std::endl;

	std::cout << "Lives: ";
	for (int i = 0; i < player1->lives; i++)
		std::cout << "_ ";
	std::cout << spaces(80 - 14 - 6 + (3 - player1->lives)*2 - 6 + 1) << "Lives: ";
	for (int i = 0; i < player2->lives; i++)
		std::cout << "_ ";
	std::cout << std::endl;

	std::cout << " Ammo: ";
	for (int i = 0; i < player1->ammo; i++)
		std::cout << "_ ";
	std::cout << spaces(80 - 12 - 6 + (3 - player1->ammo) * 2 - 6) << "Ammo: ";
	for (int i = 0; i < player2->ammo; i++)
		std::cout << "_ ";
	std::cout << std::endl;
}

int main() {
	// initialising grid
	for (int y = 0; y < 40; y++)
		for (int x = 0; x < 40; x++)
			grid[y][x] = false;
	GenerateMaze(grid);
	// update grid with new data
	
	loadGrid();
	
	displayStats();

	while (true) {
		// poll for events
		if (GetKeyState(VK_LSHIFT) & 0x8000) {
			if (player1->shoot(*player2, grid))
				player2->lives--;
			displayStats();
		} else if (GetKeyState('W') & 0x8000) {
			player1->move(direction::up, grid);
		} else if (GetKeyState('A') & 0x8000) {
			player1->move(direction::left, grid);
		} else if (GetKeyState('S') & 0x8000) {
			player1->move(direction::down, grid);
		} else if (GetKeyState('D') & 0x8000) {
			player1->move(direction::right, grid);
		}

		if (GetKeyState(VK_RSHIFT) & 0x8000) {
			if (player2->shoot(*player1, grid))
				player1->lives--;
			displayStats();
		} else if (GetKeyState(VK_UP) & 0x8000) {
			player2->move(direction::up, grid);
		} else if (GetKeyState(VK_LEFT) & 0x8000) {
			player2->move(direction::left, grid);
		} else if (GetKeyState(VK_DOWN) & 0x8000) {
			player2->move(direction::down, grid);
		} else if (GetKeyState(VK_RIGHT) & 0x8000) {
			player2->move(direction::right, grid);
		}

		// delay because the computer is too fast
		Sleep(100);
	}

	return 0;
}