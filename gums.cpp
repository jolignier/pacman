#include "gums.h"

Gums::Gums(int x, int y, int wallSize, int s, int p, QObject *parent, QColor color) :
    Edible(x, y, s, p, parent){
    offset = wallSize / 2 - boundingRect().width() / 2;
    QRectF rect = this->boundingRect();
    this->setRect(rect);
    this->color = color;
}

void Gums::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget *widget){
    const QRectF rect(boundingRect().x() + offset, boundingRect().y() + offset, boundingRect().width(), boundingRect().height());
    painter->setBrush(QBrush(this->color));
    painter->drawEllipse(rect);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Gums::eaten(){};
