#ifndef GUMS_H
#define GUMS_H

#include "edible.h"

class Gums : public Edible {

private:
    int offset;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget *widget);

public:

    Gums(int x, int y, int wallSize, int s, int p, QObject *parent);



};

#endif
