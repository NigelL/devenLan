#include "AmmoPack.h"

void AmmoPack::activate(Player &player) {
	player.ammo += this->boost;
}