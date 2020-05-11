#ifndef CHARACTER_H
#define CHARACTER_H

#include <stdlib.h>
#include <QString>
#include "Direction.h"

using namespace std;

class Character {

private:
	int posX;
	int posY;
	int sprite;
	double speed;
	Direction direction;

public:
    Character();

	Character(int x, int y, int sprite);

	int getPosX();

	void setPosX(int posX);

	int getPosY();

	void setPosY(int posY);

	void getSprite();

    void setSprite(QString name);

	void setSpeed(double speed);

	Direction getDirection();

	void setDirection(Direction direction);

    void move(Direction dir);
};

#endif
