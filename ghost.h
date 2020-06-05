#ifndef GHOST_H
#define GHOST_H

#include <stdlib.h>
#include "character.h"
#include "node.h"

using namespace std;

class Ghost : public Character {

private:
    bool affraid;
    bool chasing;
    vector<Node> chemin;

public:
    Ghost(QObject *parent, double x, double y, QPixmap* sprite);

    bool isAffraid();
    bool isChasing();

    virtual void rotateSprite(Direction dir);
};

#endif
