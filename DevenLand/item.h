#ifndef ITEM_H
#define ITEM_H

struct Item {
	// states the coordinate of the item
	int x, y;

	// states the magnitude of the effect
	int magnitude;
	
	// stores the icon of the item 
	const char icon;

	// Default initialiser 
	Item();

	// Initialiser with specified values
	Item(int x, int y, const char icon, int magnitude);

	// Default destructor
	~Item();

private:

	// spawns the item on the grid
	void spawn();

	// despawns the item on the grid
	void despawn();
};

#endif