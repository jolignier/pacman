#include "character.h"

#include <QDebug>

Character::Character(QObject *parent, double x, double y, QPixmap* sprite, double speed, Direction dir, int size) :
    QObject(parent), QGraphicsItem()
{
    this->currentFrame = 0;
    this->sprite = sprite;
    this->setPos(x, y);
    this->speed = speed;
    this->direction = dir;
    this->size = size;
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
            int boardX_min = pos().x() / Board::wallSize;
            int boardX_max = (pos().x()+size) / Board::wallSize;
            int boardY = (pos().y()-speed) / Board::wallSize;
            if (!Board::isWall(boardX_min, boardY) && !Board::isWall(boardX_max, boardY))
                setPos(pos().x(), pos().y()-speed);
            break;
        }
        case DOWN:{
            int boardX_min = pos().x() / Board::wallSize;
            int boardX_max = (pos().x()+size) / Board::wallSize;
            int boardY = (pos().y()+speed + size) / Board::wallSize;                        // Adding size for height of sprite because its
            if (!Board::isWall(boardX_min, boardY) && !Board::isWall(boardX_max, boardY))   // considering the left upper corner as ref point
                setPos(pos().x(), pos().y()+speed);
            break;
        }
        case LEFT:{
            int boardX = (pos().x()-speed) / Board::wallSize;
            int boardY_min = pos().y() / Board::wallSize;
            int boardY_max = (pos().y()+size) / Board::wallSize;
            if (!Board::isWall(boardX, boardY_min) && !Board::isWall(boardX,boardY_max))
                setPos(pos().x()-speed, pos().y());
            break;
        }
        case RIGHT:{
            int boardX = (pos().x() + speed + size) / Board::wallSize; // Same as DOWN for the width
            int boardY_min = pos().y() / Board::wallSize;
            int boardY_max = (pos().y()+size) / Board::wallSize;
            if (!Board::isWall(boardX, boardY_min) && !Board::isWall(boardX,boardY_max))
                setPos(pos().x()+speed, pos().y());
            break;
        }
        case NONE: break;
    }
}

QRectF Character::boundingRect() const {
    return QRectF(0,0,size,size);
}

void Character::nextFrame() {
    this->currentFrame += this->size;
    if (currentFrame >= this->sprite->size().width())
        this->currentFrame = 0;
    this->move();
    this->update(0,0,size,size);
}

void Character::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget *widget){
    painter->drawPixmap(0, 0, *sprite, currentFrame, 0, size, size);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
