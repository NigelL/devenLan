#include "AmmoPack.h"

// action for activating the effect on the specified player
void AmmoPack::activate(Player &player) {
	player.ammo += this->magnitude;
}

AmmoPack::AmmoPack(int x, int y, const char icon, int magnitude) : Item(x, y, icon, magnitude) {}