#ifndef ITEM_H
#define ITEM_H

struct Item {
	int x, y, boost;
	const char icon;

	Item();
	Item(int x, int y, const char icon, int boost);
	~Item();

	private:
	void spawn();
	void despawn();
};

#endif