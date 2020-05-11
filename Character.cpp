#include "Character.h"

Character::Character(int x, int y, int sprite) {
	// TODO - implement Character::Character
	throw "Not yet implemented";
}

int Character::getPosX() {
	return this->posX;
}

void Character::setPosX(int posX) {
	this->posX = posX;
}

int Character::getPosY() {
	return this->posY;
}

void Character::setPosY(int posY) {
	this->posY = posY;
}

void Character::getSprite() {
	// TODO - implement Character::getSprite
	throw "Not yet implemented";
}

void Character::setSprite(QString name) {
	// TODO - implement Character::setSprite
	throw "Not yet implemented";
}

void Character::setSpeed(double speed) {
	this->speed = speed;
}

Direction Character::getDirection() {
	return this->direction;
}

void Character::setDirection(Direction direction) {
	this->direction = direction;
}

void Character::move(Direction dir) {
	// TODO - implement Character::move
	throw "Not yet implemented";
}
