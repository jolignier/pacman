#ifndef PLAYER_H
#define PLAYER_H

#include <stdlib.h>
#include <QKeyEvent>

#include "direction.h"
#include "character.h"

using namespace std;

class Player : public Character {

private:
	int nbLife;
	Direction futureDirection;

public:
    Player(QObject *parent, double x, double y);

	int getNbLife();
	void setNbLife(int nbLife);

	Direction getFutureDirection();
	void setFutureDirection(Direction futureDirection);

    void keyPressEvent(QKeyEvent *event);
};

#endif
