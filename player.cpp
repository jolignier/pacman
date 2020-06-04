#include "player.h"

#include <QDebug>

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
            setFutureDirection(UP);
            break;
        case Qt::Key_Down:
            setFutureDirection(DOWN);
            break;
        case Qt::Key_Left:
            setFutureDirection(LEFT);
            break;
        case Qt::Key_Right:
            setFutureDirection(RIGHT);
            break;
    }
}

void Player::nextFrame(){
    this->applyFutureDirection();
    Character::nextFrame();

}

void Player::applyFutureDirection() {
    if (futureDirection != NONE){
        if (canMove(futureDirection)){
            setDirection(futureDirection);
            setFutureDirection(NONE);
        }
    }
}
