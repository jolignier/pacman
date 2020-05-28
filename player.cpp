#include "player.h"

Player::Player(QObject *parent, double x, double y) :
    Character(parent, x, y, new QPixmap(":/sprites/player/pac"))
{
    this->nbLife = 3;
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

void Player::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
        case Qt::Key_Up:
            setDirection(UP);
            break;
        case Qt::Key_Down:
            setDirection(DOWN);
            break;
        case Qt::Key_Left:
            setDirection(LEFT);
            break;
        case Qt::Key_Right:
            setDirection(RIGHT);
            break;
    }
}
