#include "inky.h"

Inky::Inky(QObject *parent, double x, double y):
    Ghost(parent, x, y, new QPixmap(":/sprites/inky/up")){
}

QPair<int,int> Inky::getTarget(){
    QPair<int,int> res;
    switch (this->getMode()){
        case SCATTER:
            res = QPair<int,int>(27,29);
            break;
        case CHASE:{
            res = QPair<int,int>(27,29);
            // Inky is focusing on helping Blinky
            // Firstly get the distance between Pac and Blinky
            // Next rotate this distance 180° to get Inky focusing Target

            // If distance = 5 and Blinky is at the top right of pacman
            // Inky will focus with distance = 5 on the bottom left
            res = getChaseTarget();
            break;
        }
        case EATEN:{
            // Targets the door and when is at the door
            // Targets its own cell
            res = QPair<int,int>(14,11);
            if (this->getPosition() == res || this->isInHome()){
                res = QPair<int,int>(14,14);
            }
            break;
        }
    }
    return res;
}

QPair<int,int> Inky::getChaseTarget(){
    int delta_x = getPlayer()->getPosition().first - this->blinky->getPosition().first;
    int delta_y = getPlayer()->getPosition().second - this->blinky->getPosition().second;

    int x = getPlayer()->getPosition().first + delta_x;
    int y = getPlayer()->getPosition().second + delta_y;

    return QPair<int,int>(x,y);
}

void Inky::rotateSprite(Direction dir){
    QString prefix;

    switch (this->getMode()){
        case SCATTER:
        case CHASE:
        case PATTERN:
            prefix = ":/sprites/inky/";
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

void Inky::setBlinky(Blinky* blinky){
    this->blinky = blinky;
}

void Inky::nextFrame(){
    if (this->getPosition() == QPair<int,int>(14,14) && this->getMode() == EATEN){
        this->disableEatenMode();
    }
    Ghost::nextFrame();
}
