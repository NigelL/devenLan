#ifndef TILE_H
#define TILE_H

#include "item.h"

// Data structure for a tile in the grid

struct Tile {
	// states whether this tile is blocked
	bool isBlocked;

	// states whether this item has an item
	// NULL - no item present
	Item* item;

	// Default initialiser for the tile
	Tile();

	// Initialiser with specified values
	Tile(bool b, Item* i);
};

#endif