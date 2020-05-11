#ifndef GRAPHE_H
#define GRAPHE_H

#include <stdlib.h>
#include <vector>
#include "Node.h"
#include "Cell.h"

using namespace std;

class Graphe {

private:
    //vector<Node> vertices;
	int infinite;

public:
	Graphe();

	void addNode(Cell c);

	void addVertice(Cell c1, Cell c2);

	void getNodes();

	void getInfinite();

	void getNode(Cell c);
};

#endif
