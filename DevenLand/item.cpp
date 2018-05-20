#include "item.h"
#include <windows.h>

Item::Item() : x(0), y(0), icon(' ') {
	spawn();
}

Item::Item(int x, int y, const char icon, int boost) : x(x), y(y), icon(icon), boost(boost) {
	spawn();
}

Item::~Item() {
	despawn();
}

void Item::spawn() {
	DWORD dw; // no idea
	COORD pos = { this->x*2, this->y };
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // no idea
	if (hStdOut == INVALID_HANDLE_VALUE) return;
	WriteConsoleOutputCharacter(hStdOut, &this->icon, 1, pos, &dw);
}

void Item::despawn() {
	DWORD dw; // no idea
	COORD pos = { this->x * 2, this->y };
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // no idea
	if (hStdOut == INVALID_HANDLE_VALUE) return;
	WriteConsoleOutputCharacter(hStdOut, " ", 1, pos, &dw);
}