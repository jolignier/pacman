#ifndef GHOST_H
#define GHOST_H

#include <stdlib.h>
#include "character.h"
#include "node.h"
#include "ghostmode.h"
#include "astar.h"

using namespace std;

class Ghost : public Character {

    Q_OBJECT

private:
    GhostMode mode;
    QPair<int,int> target;
    QList<Node*> path;
    QTimer* timer;
    int nbScatterCycle;
    Graphe graphe;
    Astar astar;

    QPair<int,int> lastIntersection;

public slots:
    void onSpawn();
    void swapMode();

public:
    Ghost(QObject *parent, double x, double y, Graphe graphe, QPixmap* sprite);

    int getModeChangeTime();

    bool isAffraid();
    GhostMode getMode();
    void setMode(GhostMode mode);

    QList<Node*> getPath();

    void calculateNewPath();
    Direction getDirectionFromPath();

    Direction getNextDirection();
    Direction nextDirectionToTest(Direction current);
    bool isOppositeDirection(Direction dir);
    bool isNotLastIntersection(int x, int y);

    void nextFrame();

    virtual QPair<int,int> getTarget() = 0;
    virtual void rotateSprite(Direction dir) = 0;
};

#endif
