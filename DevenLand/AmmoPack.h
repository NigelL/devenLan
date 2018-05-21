#ifndef AMMOPACK_H
#define AMMOPACK_H

#include "player.h"
#include "item.h"

// Gives the player ammo

struct AmmoPack : public Item {
	// action for activating the effect on the specified player
	void activate(Player &player);

	AmmoPack::AmmoPack(int x, int y, const char icon, int magnitude);
};

#endif 
