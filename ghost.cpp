#include "ghost.h"

Ghost::Ghost(QObject *parent, double x, double y, QPixmap* sprite) :
    Character(parent, x, y, sprite) {

}

bool Ghost::isAffraid() {
    return affraid;
}

bool Ghost::isChasing() {
    return chasing;
}

vector<Node> Ghost::getPath(){
    return path;
}

void Ghost::rotateSprite(Direction dir){}
