#include "item.h"
#include <windows.h>

// Default initialiser 
Item::Item() : x(0), y(0), icon(' ') {
	// when item is initialised, spawn it on the map.
	spawn();
}

// Initialiser with specified values
Item::Item(int x, int y, const char icon, int magnitude) : x(x), y(y), icon(icon), magnitude(magnitude) {
	// when item is initialised, spawn it on the map.
	spawn();
}

// Default destructor
Item::~Item() {
	// when item is destroyed, remove it on the map.
	despawn();
}

// spawns the item on the grid
void Item::spawn() {
	DWORD dw; // no idea
	COORD pos = { this->x*2, this->y };
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // no idea
	if (hStdOut == INVALID_HANDLE_VALUE) return;
	WriteConsoleOutputCharacter(hStdOut, &this->icon, 1, pos, &dw);
}

// despawns the item on the grid
void Item::despawn() {
	DWORD dw; // no idea
	COORD pos = { this->x * 2, this->y };
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // no idea
	if (hStdOut == INVALID_HANDLE_VALUE) return;
	WriteConsoleOutputCharacter(hStdOut, " ", 1, pos, &dw);
}