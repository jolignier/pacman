#ifndef INKY_H
#define INKY_H

#include "ghost.h"
#include "blinky.h"


class Inky : public Ghost {


private:
    Blinky* blinky;

public:
    Inky(QObject *parent, double x, double y);

    QPair<int,int> getTarget() override;
    void rotateSprite(Direction dir) override;

    QPair<int,int> getChaseTarget();
    void setBlinky(Blinky* blinky);
};

#endif

