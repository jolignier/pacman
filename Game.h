#ifndef GAME_H
#define GAME_H

class Game {

private:
	boolean playing;

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
