#include "inky.h"

Inky::Inky(QObject *parent, double x, double y, QPixmap* sprite):
    Ghost(parent, x, y, sprite){

}

void Inky::rotateSprite(Direction dir){
    switch (dir) {
        case UP:
            this->setSprite(new QPixmap(":/sprites/inky/up"));
            break;
        case DOWN:
            this->setSprite(new QPixmap(":/sprites/inky/down"));
            break;
        case LEFT:
            this->setSprite(new QPixmap(":/sprites/inky/left"));
            break;
        case RIGHT:
            this->setSprite(new QPixmap(":/sprites/inky/right"));
            break;

    }
}
