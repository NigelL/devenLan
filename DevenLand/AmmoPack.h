#ifndef AMMOPACK_H
#define AMMOPACK_H

#include "player.h"
#include "item.h"

struct AmmoPack : public Item {
	void activate(Player &player);

	AmmoPack::AmmoPack(int x, int y, const char icon, int boost);
};

#endif 
