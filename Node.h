#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include <vector>

#include <QPair>

using namespace std;

class Node {

private:
    vector<Node> neighbors;
    //Graphe graphe;
    QPair<int,int> linkedCell;

public:
    Node();

    //Node(Graphe g, QPair<int,int> cell);

    Node(const Node& n);

    void addNeighbour(QPair<int,int> cell);

	void getNeighbors();
};

#endif
