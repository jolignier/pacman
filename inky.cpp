#include "inky.h"

Inky::Inky(QObject *parent, double x, double y, Graphe graphe, QPixmap* sprite):
    Ghost(parent, x, y, graphe, sprite){
}

QPair<int,int> Inky::getTarget(){
    return QPair<int,int>(27,29);
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
