#include "clyde.h"

#include <QDebug>

Clyde::Clyde(QObject *parent, double x, double y):
    Ghost(parent, x, y, new QPixmap(":/sprites/clyde/up")){
}

QPair<int,int> Clyde::getTarget(){
    QPair<int,int> res;
    switch (this->getMode()){
        case SCATTER:
            res = QPair<int,int>(2,29);
            break;
        case CHASE:{
            // Clyde acts like blinky, when is 8 tiles far from pac
            // If the distance is greater than 8 tiles, he will chase pac position
            // Elsewise he will focus his corner from SCATTER MODE
            res = getChaseTarget();
            break;
        }
        case EATEN:
            res = QPair<int,int>(15,14);
            break;
        case FRIGHTENED:{
            break;
        }
    }
    return res;
}

QPair<int,int> Clyde::getChaseTarget(){
    QPair<int,int> res;
    int delta_x = getPlayer()->getPosition().first - this->getPosition().first;
    int delta_y = getPlayer()->getPosition().second - this->getPosition().second;
    int distance = abs(delta_x) + abs(delta_y);
    if (distance > 8){
        res = getPlayer()->getPosition();
    } else {
        res = QPair<int,int>(2,29);
    }
    return res;
}

void Clyde::rotateSprite(Direction dir){
    QString prefix;

    switch (this->getMode()){
        case SCATTER:
        case CHASE:
            prefix = ":/sprites/clyde/";
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
