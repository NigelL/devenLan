#include <iostream>

// true - wall. false - free
bool grid[40][40];

int main() {
	for (int x = 0; x < 40; x++)
		for (int y = 0; y < 40; y++)
			grid[x][y] = false;
	return 0;
}