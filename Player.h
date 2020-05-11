#ifndef PLAYER_H
#define PLAYER_H

#include <stdlib.h>
#include "Direction.h"
#include "Character.h"

using namespace std;

class Player : Character {

private:
	int nbLife;
	Direction futureDirection;

public:
	Player();

	int getNbLife();

	void setNbLife(int nbLife);

	Direction getFutureDirection();

	void setFutureDirection(Direction futureDirection);
};

#endif
