#ifndef HEALTHPACK_H
#define HEALTHPACK_H

#include "player.h"
#include "item.h"

struct HealthPack: public Item {
	void activate(Player &player);

	HealthPack(int x, int y, const char icon, int boost);
};

#endif 
