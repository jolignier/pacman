#ifndef PINKY_H
#define PINKY_H

#include "ghost.h"

class Pinky : public Ghost {

public:
    Pinky(QObject *parent, double x, double y);

    QPair<int,int> getChaseTarget();

    QPair<int,int> getTarget() override;
    void rotateSprite(Direction dir) override;

    void nextFrame();
};

#endif
