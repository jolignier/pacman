#include "character.h"

#include <QDebug>

Character::Character(QObject *parent, double x, double y, QPixmap* sprite, double speed, Direction dir, int size) :
    QGraphicsItem()
{
    this->currentFrame = 0;
    this->sprite = sprite;
    this->setPos(x, y);
    this->speed = speed;
    this->direction = dir;
    this->futureDirection = NONE;
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

Direction Character::getFutureDirection() {
    return this->futureDirection;
}

void Character::setFutureDirection(Direction direction) {
    this->futureDirection = direction;
}

void Character::applyFutureDirection(){
    if (futureDirection != NONE){
        if (canMove(futureDirection)){
            // Rotating sprite
            rotateSprite(futureDirection);
            // Applying direction
            setDirection(futureDirection);
            setFutureDirection(NONE);
        }
    }
}

bool Character::canMove(Direction dir){
    bool res = false;
    switch (dir) {
        case UP: {
            int boardX_min = pos().x() / Board::wallSize;
            int boardX_max = (pos().x()+size) / Board::wallSize;
            int boardY = (pos().y()-speed) / Board::wallSize;
            res =  (!Board::isWall(boardX_min, boardY) && !Board::isWall(boardX_max, boardY));
            break;
        }
        case DOWN:{
            int boardX_min = pos().x() / Board::wallSize;
            int boardX_max = (pos().x()+size) / Board::wallSize;
            int boardY = (pos().y()+speed + size) / Board::wallSize;                        // Adding size for height of sprite because its
            res =  (!Board::isWall(boardX_min, boardY) && !Board::isWall(boardX_max, boardY));
            break;
        }
        case LEFT:{
            int boardX = (pos().x()-speed) / Board::wallSize;
            int boardY_min = pos().y() / Board::wallSize;
            int boardY_max = (pos().y()+size) / Board::wallSize;
            res =  (!Board::isWall(boardX, boardY_min) && !Board::isWall(boardX,boardY_max));
            break;
        }
        case RIGHT:{
            int boardX = (pos().x() + speed + size) / Board::wallSize; // Same as DOWN for the width
            int boardY_min = pos().y() / Board::wallSize;
            int boardY_max = (pos().y()+size) / Board::wallSize;
            res = (!Board::isWall(boardX, boardY_min) && !Board::isWall(boardX,boardY_max));
            break;
        }
        case NONE: break;
    }
    return res;
}

void Character::move() {
    switch (direction) {
        case UP: {
            if (canMove(direction))
                setPos(pos().x(), pos().y()-speed);
            break;
        }
        case DOWN:{
            if (canMove(direction))
                setPos(pos().x(), pos().y()+speed);
            break;
        }
        case LEFT:{
            if (canMove(direction)) {
                if (pos().x()-speed < 15) setPos(600, pos().y()); // Teleport to right side of map
                else setPos(pos().x()-speed, pos().y());
            }
            break;
        }
        case RIGHT:{
            if (canMove(direction)) {
                if (pos().x()+speed > 600) setPos(15, pos().y()); // Teleport to left side of map
                else setPos(pos().x()+speed, pos().y());
            }
            break;
        }
        case NONE: break;
    }
}

QRectF Character::boundingRect() const {
    return QRectF(0,0,size,size);
}

void Character::nextFrame() {
    this->applyFutureDirection();
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
