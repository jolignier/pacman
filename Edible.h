#ifndef EDIBLE_H
#define EDIBLE_H

#include <stdlib.h>
#include <QGraphicsItem>
#include <QPainter>

using namespace std;

class Edible : public QObject, public QGraphicsEllipseItem {
Q_OBJECT

private:

	int points;
    int size;

public:

    int getPoints();
    QRectF boundingRect() const;
    Edible(int x, int y, int s, int p, QObject *parent);

};

#endif
