#ifndef HEALTHPACK_H
#define HEALTHPACK_H

#include "item.h"

struct HealthPack: public Item {
	void activate(Player &player);
};

#endif 
