#ifndef PLAYER_H
#define PLAYER_H

#include <stdlib.h>
#include <QKeyEvent>

#include "direction.h"
#include "character.h"

using namespace std;

class Player : public Character {

    Q_OBJECT

private:
    int nbLife;
    bool superMode;
    int scoreMultiplier;

    QTimer* timer;

public slots:
    void onSuperGumEaten();
    void disableSuperMode();

public:
    Player(QObject *parent, double x, double y);

	int getNbLife();
    void setNbLife(int nbLife);

    bool isSuperMode();

    int getScoreMultiplier();
    void increaseScoreMultiplier();

    bool canMove(Direction dir);

    void keyPressEvent(QKeyEvent *event) override;
    void rotateSprite(Direction dir) override;
};

#endif
