#include "AmmoPack.h"

void AmmoPack::activate(Player &player) {
	player.ammo += this->boost;
}

AmmoPack::AmmoPack(int x, int y, const char icon, int boost) : Item(x, y, icon, boost) {}