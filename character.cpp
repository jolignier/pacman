#include "character.h"

#include <QDebug>

Character::Character(QObject *parent, double x, double y, QPixmap* sprite, double speed, Direction dir) :
    QObject(parent), QGraphicsItem()
{
    this->currentFrame = 0;
    this->sprite = sprite;
    this->setPos(x, y);
    this->speed = speed;
    this->direction = dir;
}

QPixmap* Character::getSprite() {
    return this->sprite;
}

void Character::setSprite(QPixmap* sprite) {
    this->sprite = sprite;
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

void Character::move() {

    switch (direction) {
        case UP: {
            int boardX = pos().x() / Board::wallSize;
            int boardY = (pos().y()-speed) / Board::wallSize;
            if (!Board::isWall(boardX, boardY))
                setPos(pos().x(), pos().y()-speed);
            break;
        }
        case DOWN:{
            int boardX = pos().x() / Board::wallSize;
            int boardY = (pos().y()+speed) / Board::wallSize;
            if (!Board::isWall(boardX, boardY))
                setPos(pos().x(), pos().y()+speed);
            break;
        }
        case LEFT:{
            int boardX = (pos().x()-speed) / Board::wallSize;
            int boardY = pos().y() / Board::wallSize;
            if (!Board::isWall(boardX, boardY))
                setPos(pos().x()-speed, pos().y());
            break;
        }
        case RIGHT:{
            int boardX = (pos().x()+speed) / Board::wallSize;
            int boardY = pos().y() / Board::wallSize;
            if (!Board::isWall(boardX, boardY))
                setPos(pos().x()+speed, pos().y());
            break;
        }
    }
}

QRectF Character::boundingRect() const {
    return QRectF(0,0,frameShift,frameShift);
}

void Character::nextFrame() {
    this->currentFrame += this->frameShift;
    if (currentFrame >= this->sprite->size().width())
        this->currentFrame = 0;
    this->move();
    this->update(0,0,frameShift,frameShift);
}

void Character::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget *widget){
    painter->drawPixmap(0, 0, *sprite, currentFrame, 0, frameShift, frameShift);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

