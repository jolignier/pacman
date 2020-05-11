#ifndef CELL_H
#define CELL_H

#include <stdlib.h>

using namespace std;

class Cell {

private:
	int x;
	int y;

public:
	int getX();

	int getY();

	Cell(int x, int y);

    Cell();
};

#endif
