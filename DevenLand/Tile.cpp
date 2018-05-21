#include "Tile.h"

Tile::Tile() : isBlocked(false), item(nullptr) {}
Tile::Tile(bool b, Item* i) : isBlocked(b), item(i) {}