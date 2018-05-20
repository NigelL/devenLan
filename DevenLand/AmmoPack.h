#ifndef AMMOPACK_H
#define AMMOPACK_H

#include "item.h"

struct AmmoPack : public Item {
	void activate(Player &player);
};

#endif 
