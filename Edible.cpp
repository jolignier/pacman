#include "edible.h"


int Edible::getPoints() {
    return this->points;
}

QRectF Edible::boundingRect() const{
    return QRectF(0,0,size,size);
}

Edible::Edible(int x, int y, int s, int p, QObject *parent) :
    QObject(parent), QGraphicsEllipseItem()
{

    this->setPos(x, y);
    this->size = s;
    this->points = p;

}

