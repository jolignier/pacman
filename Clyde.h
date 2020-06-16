#ifndef CLYDE_H
#define CLYDE_H

#include "ghost.h"

class Clyde : public Ghost {

public:
    Clyde(QObject *parent, double x, double y);

    QPair<int,int> getTarget() override;
    void rotateSprite(Direction dir) override;

    QPair<int,int> getChaseTarget();
    void nextFrame();
};

#endif
