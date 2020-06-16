#include "pinky.h"

Pinky::Pinky(QObject *parent, double x, double y):
    Ghost(parent, x, y, new QPixmap(":/sprites/pinky/up")){
}

// Pinky always target 4 tiles in front of pacman
// When chasing

QPair<int,int> Pinky::getTarget(){
    QPair<int,int> res;
    switch (this->getMode()){
        case SCATTER:
            res = QPair<int,int>(2,1);
            break;
        case CHASE:
            res = this->getChaseTarget();
            break;
        case EATEN:
            res = QPair<int,int>(14,14);
            break;
        case FRIGHTENED:
            break;
    }
    return res;
}

QPair<int,int> Pinky::getChaseTarget(){
    int x = getPlayer()->getPosition().first;
    int y = getPlayer()->getPosition().second;
    switch(getPlayer()->getDirection()){
        case UP:
            y -= 4;
            break;
        case DOWN:
            y+= 4;
            break;
        case LEFT:
            x -= 4;
            break;
        case RIGHT:
            x += 4;
            break;
    }
    return QPair<int,int>(x,y);
}


void Pinky::rotateSprite(Direction dir){
    QString prefix;

    switch (this->getMode()){
        case SCATTER:
        case CHASE:
            prefix = ":/sprites/pinky/";
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
        case LEFT:case NONE:
            this->setSprite(new QPixmap(prefix + "left"));
            break;
        case RIGHT:
            this->setSprite(new QPixmap(prefix + "right"));
            break;
    }
}

void Pinky::nextFrame(){
    if (this->getPosition() == QPair<int,int>(13,14) && this->getMode() == EATEN){
        this->disableEatenMode();
    }
    Ghost::nextFrame();
}
