#include "blinky.h"

#include <QDebug>

Blinky::Blinky(QObject *parent, double x, double y):
    Ghost(parent, x, y, new QPixmap(":/sprites/blinky/up")){
}

QPair<int,int> Blinky::getTarget(){
    QPair<int,int> res;
    switch (this->getMode()){
        case SCATTER:
            res = QPair<int,int>(27,1);
            break;
        case CHASE:
            res = getPlayer()->getPosition();
            break;
        case EATEN:
            res = QPair<int,int>(13,14);
            break;
        case FRIGHTENED:
            break;
    }
    return res;
}

void Blinky::rotateSprite(Direction dir){
    switch (dir) {
        case UP:
            this->setSprite(new QPixmap(":/sprites/blinky/up"));
            break;
        case DOWN:
            this->setSprite(new QPixmap(":/sprites/blinky/down"));
            break;
        case LEFT:case NONE:
            this->setSprite(new QPixmap(":/sprites/blinky/left"));
            break;
        case RIGHT:
            this->setSprite(new QPixmap(":/sprites/blinky/right"));
            break;
    }
}
