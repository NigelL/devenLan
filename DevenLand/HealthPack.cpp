#include "HealthPack.h"

// action for activating the effect on the specified player
void HealthPack::activate(Player &player) { 
	player.lives += this->magnitude;
}

// Initialiser with specified values
HealthPack::HealthPack(int x, int y, const char icon, int magnitude): Item(x, y, icon, magnitude) {}