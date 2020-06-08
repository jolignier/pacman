#ifndef ASTAR_H
#define ASTAR_H

#include <stdlib.h>
#include <vector>
#include <QHash>

#include "node.h"
#include "graphe.h"

using namespace std;

class Astar {

private:
    Graphe graphe;
    Node* starting;
    Node* ending;
    QHash<Node*, int> distance;
    QHash<Node*, bool> visited;
    QHash<Node*, Node*> predecessor;
    QList<Node*> path;


public:
	Astar(Graphe g);

	void initialize();

    Node* getClosestNode();

    double getHeuristic(Node* n);

    void calcul(Node* starting, Node* ending);

    QList<Node*> getPath();
};

#endif
