#include "superGum.h"

SuperGum::SuperGum(int x, int y, int wallSize, QObject *parent) :
    Gums(x, y, wallSize, 15, 50, parent, QColor(255,200,0)) {
    connect(this, SIGNAL(superEaten()), parent, SLOT(superGumEaten()));
}

void SuperGum::eaten(){
    emit superEaten();
}

