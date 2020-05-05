#ifndef PLAYER_H
#define PLAYER_H

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
