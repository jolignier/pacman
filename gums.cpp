#include "gums.h"

Gums::Gums(int x, int y, int wallSize, int s, int p, QObject *parent) :
    Edible(x, y, s, p, parent){
    offset = wallSize / 2 - boundingRect().width() / 2;
    QRectF rect = this->boundingRect();
    this->setRect(rect);
}

void Gums::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget *widget){
    const QRectF rect(boundingRect().x() + offset, boundingRect().y() + offset, boundingRect().width(), boundingRect().height());
    painter->setBrush(QBrush(QColor(250,200,0)));
    painter->drawEllipse(rect);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
