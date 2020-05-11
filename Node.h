#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include <vector>
#include "Graphe.h"
#include "Cell.h"

using namespace std;

class Node {

private:
    vector<Node> neighbors;
    //Graphe graphe;
	Cell linkedCell;

public:
    Node();

    //Node(Graphe g, Cell c);

    Node(const Node& n);

	void addNeighbour(Cell c);

	void getNeighbors();
};

#endif
