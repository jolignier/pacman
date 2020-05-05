#ifndef BOARD_H
#define BOARD_H

class Board {


public:
	Board();

	void generate();

	void getCell(int x, int y);

	int getGumsNumber();

	void newFruit();
};

#endif
