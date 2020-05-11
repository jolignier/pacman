#ifndef EDIBLE_H
#define EDIBLE_H

#include <stdlib.h>

using namespace std;

class Edible {

private:
	int sprite;
	int posX;
	int posY;
	int points;

public:
	void getPosX();

	void getPosY();

	void getPoints();

	Edible(int x, int y, int p);
};

#endif
