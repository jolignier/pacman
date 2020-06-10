#ifndef INKY_H
#define INKY_H

#include "ghost.h"


class Inky : public Ghost {


public:
    Inky(QObject *parent, double x, double y, Graphe graphe, QPixmap* sprite);

    QPair<int,int> getTarget() override;
    void rotateSprite(Direction dir) override;
};

#endif

