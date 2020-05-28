#include "player.h"

Player::Player(QObject *parent, double x, double y) :
    Character(parent, x, y, new QPixmap(":inky_up"))
{
    this->nbLife = 1;
    this->setDirection(LEFT);
    this->setFutureDirection(NONE);
}

int Player::getNbLife() {
	return this->nbLife;
}

void Player::setNbLife(int nbLife) {
	this->nbLife = nbLife;
}

Direction Player::getFutureDirection() {
	return this->futureDirection;
}

void Player::setFutureDirection(Direction futureDirection) {
	this->futureDirection = futureDirection;
}
