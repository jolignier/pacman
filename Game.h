#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <QString>
#include <QRect>

using namespace std;

class Game {

private:
    bool playing;

public:
	Game();

	void hasWin();

	void hasLost();

	void win();

	void lose();

	void displayMenu();

    void newGame();
};

#endif
