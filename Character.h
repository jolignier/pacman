#ifndef CHARACTER_H
#define CHARACTER_H

class Character {

private:
	int posX;
	int posY;
	int sprite;
	double speed;
	Direction direction;

public:
	Character(int x, int y, int sprite);

	int getPosX();

	void setPosX(int posX);

	int getPosY();

	void setPosY(int posY);

	void getSprite();

	void setSprite(string name);

	void setSpeed(double speed);

	Direction getDirection();

	void setDirection(Direction direction);

	void move(Direction dir);
};

#endif
