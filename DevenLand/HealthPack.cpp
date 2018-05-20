#include "HealthPack.h"

void HealthPack::activate(Player &player) {
	player.lives += this->boost;
}