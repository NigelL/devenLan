#ifndef TILE_H
#define TILE_H

#include "item.h"

struct Tile {
	bool isBlocked;
	Item* item;

	Tile();
	Tile(bool b, Item* i);
};

#endif