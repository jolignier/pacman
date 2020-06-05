#ifndef INKY_H
#define INKY_H

#include "ghost.h"


class Inky : public Ghost {


public:
    Inky(QObject *parent, double x, double y, QPixmap* sprite);

    void rotateSprite(Direction dir);

};

#endif

