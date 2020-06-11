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

    Q_OBJECT

private:
    QPixmap* sprite;
	double speed;
	Direction direction;
    Direction futureDirection;
    int currentFrame;
    int size;


    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget *widget);    

public:
    Character(QObject *parent, double x, double y, QPixmap* sprite, double speed=3, Direction dir=LEFT, int size=20);

    QPixmap* getSprite();
    void setSprite(QPixmap* sprite);
	void setSpeed(double speed);
	Direction getDirection();
	void setDirection(Direction direction);
    Direction getFutureDirection();
    void setFutureDirection(Direction futureDirection);
    void applyFutureDirection();
    bool canMove(Direction dir);
    void move();
    void nextFrame();

    QRectF boundingRect() const;
    virtual void rotateSprite(Direction dir) = 0;

};

#endif
