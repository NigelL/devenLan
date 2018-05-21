#include "Tile.h"

// Default initialiser for the tile
Tile::Tile() : isBlocked(false), item(nullptr) {}

// Initialiser with specified values
Tile::Tile(bool b, Item* i) : isBlocked(b), item(i) {}