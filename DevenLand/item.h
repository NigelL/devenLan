#ifndef ITEM_H
#define ITEM_H

#include "player.h"

struct Item {
	int x, y, boost;
	const char icon;

	Item();
	Item(int x, int y, const char icon, int boost);
	~Item();

	virtual void activate(Player &player) {};

	private:
	void spawn();
	void despawn();
};

#endif