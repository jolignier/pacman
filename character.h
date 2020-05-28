#ifndef CHARACTER_H
#define CHARACTER_H

#include <stdlib.h>
#include <QString>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

#include "direction.h"
#include "board.h"

using namespace std;

class Character : public QObject, public QGraphicsItem {

private:
    QPixmap* sprite;
	double speed;
	Direction direction;
    int currentFrame;
    int size;


    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget *widget);
    QRectF boundingRect() const;

public:
    Character(QObject *parent, double x, double y, QPixmap* sprite, double speed=3, Direction dir=LEFT, int size=20);

    QPixmap* getSprite();
    void setSprite(QPixmap* sprite);
	void setSpeed(double speed);
	Direction getDirection();
	void setDirection(Direction direction);
    void move();
    void nextFrame();

};

#endif
