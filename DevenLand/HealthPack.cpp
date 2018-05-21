#include "HealthPack.h"

void HealthPack::activate(Player &player) {
	player.lives += this->boost;
}

HealthPack::HealthPack(int x, int y, const char icon, int boost): Item(x, y, icon, boost) {}