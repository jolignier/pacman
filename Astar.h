#ifndef ASTAR_H
#define ASTAR_H

#include <stdlib.h>
#include <vector>
#include "Node.h"
#include "Graphe.h"

using namespace std;

class Astar {

private:
    //Graphe graphe;
	Node starting;
	Node ending;
    vector<pair<Node, int>> distance;
    vector<pair<Node, bool>> visited;
    vector<pair<Node, Node>> predecessor;


public:
	Astar(Graphe g);

	void initialize();

	Node getClosestNode();

	double getHeuristic();

	void calcul(Node starting, Node ending);

	void getPath();
};

#endif
