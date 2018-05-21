#ifndef HEALTHPACK_H
#define HEALTHPACK_H

#include "player.h"
#include "item.h"

// Heals the player

struct HealthPack: public Item {
	// action for activating the effect on the specified player
	void activate(Player &player);

	// Initialiser with specified values
	HealthPack(int x, int y, const char icon, int magnitude);
};

#endif 
