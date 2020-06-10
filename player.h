#ifndef PLAYER_H
#define PLAYER_H

#include <stdlib.h>
#include <QKeyEvent>

#include "direction.h"
#include "character.h"

using namespace std;

class Player : public Character {

private:
    int nbLife;

public:
    Player(QObject *parent, double x, double y);

	int getNbLife();
	void setNbLife(int nbLife);

    QPair<int,int> getPosition();

    void keyPressEvent(QKeyEvent *event) override;
    void rotateSprite(Direction dir) override;
};

#endif
