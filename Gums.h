#ifndef GUMS_H
#define GUMS_H

#include "edible.h"
#include "player.h"

class Gums : public Edible {

private:
    int offset;
    QColor color;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget *widget);

public:
    Gums(int x, int y, int wallSize, int s, int p, QObject *parent, QColor color = QColor(255,255,255));

    virtual void eaten();
};

#endif
