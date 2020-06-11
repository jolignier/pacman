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
            break;
        }
        case EATEN:
            res = QPair<int,int>(14,14);
            break;
        case FRIGHTENED:{
            break;
        }
    }
    return res;
}

void Inky::rotateSprite(Direction dir){
    switch (dir) {
        case UP:
            this->setSprite(new QPixmap(":/sprites/inky/up"));
            break;
        case DOWN:
            this->setSprite(new QPixmap(":/sprites/inky/down"));
            break;
        case LEFT:case NONE:
            this->setSprite(new QPixmap(":/sprites/inky/left"));
            break;
        case RIGHT:
            this->setSprite(new QPixmap(":/sprites/inky/right"));
            break;
    }
}

void Inky::setBlinky(Blinky* blinky){
    this->blinky = blinky;
}
