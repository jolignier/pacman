#ifndef GHOST_H
#define GHOST_H

#include <stdlib.h>
#include "character.h"
#include "ghostmode.h"
#include "player.h"

using namespace std;

class Ghost : public Character {

    Q_OBJECT

private:
    GhostMode mode;
    QPair<int,int> target;
    QTimer* timer;
    int nbScatterCycle;
    Player* player;
    QPair<int,int> lastIntersection;

    QPair<double,Direction> directionOrder[4];

public slots:
    void onSpawn();
    void swapMode();

public:
    Ghost(QObject *parent, double x, double y, QPixmap* sprite);

    int getModeChangeTime();

    bool isAffraid();
    GhostMode getMode();
    void setMode(GhostMode mode);

    Player* getPlayer();
    void setPlayer(Player* player);

    double getDistance(QPair<int,int> a, QPair<int,int> b);
    void calculateDirection();
    Direction getNextDirection();

    bool isWall(Direction dir);
    bool isOppositeDirection(Direction dir);
    bool isNotLastIntersection(int x, int y);

    void nextFrame();

    virtual QPair<int,int> getTarget() = 0;
    virtual void rotateSprite(Direction dir) = 0;
};

#endif
