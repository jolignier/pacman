#ifndef BLINKY_H
#define BLINKY_H

#include "ghost.h"

class Blinky : public Ghost {


public:
    Blinky(QObject *parent, double x, double y);

    QPair<int,int> getTarget() override;
    void rotateSprite(Direction dir) override;
};


#endif
