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
        case EATEN:{
            // Targets the door and when is at the door
            // Targets its own cell
            res = QPair<int,int>(12,11);
            if (this->getPosition() == res || this->isInHome()){
                res = QPair<int,int>(12,14);
            }
            break;
        }
    }
    return res;
}

void Blinky::rotateSprite(Direction dir){
    QString prefix;

    switch (this->getMode()){
        case SCATTER:
        case CHASE:
        case PATTERN:
            prefix = ":/sprites/blinky/";
            break;
        case FRIGHTENED:
            prefix = ":/sprites/frightened/";
        break;
        case EATEN:
            prefix = ":/sprites/eyes/";
            break;
    }

    switch (dir) {
        case UP:
            this->setSprite(new QPixmap(prefix + "up"));
            break;
        case DOWN:
            this->setSprite(new QPixmap(prefix + "down"));
            break;
        case LEFT:
            this->setSprite(new QPixmap(prefix + "left"));
            break;
        case RIGHT:
            this->setSprite(new QPixmap(prefix + "right"));
            break;
    }
}

void Blinky::nextFrame(){
    if (this->getPosition() == QPair<int,int>(12,14) && this->getMode() == EATEN){
        this->disableEatenMode();
    }
    Ghost::nextFrame();
}
