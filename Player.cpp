#include "Player.h"

Player::Player() {
	// TODO - implement Player::Player
	throw "Not yet implemented";
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
