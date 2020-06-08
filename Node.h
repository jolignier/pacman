#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include <vector>

#include <QPair>

using namespace std;

class Node {

private:
    vector<Node*>* neighbors;
    QPair<int,int> linkedCell;

public:
    Node(QPair<int,int> cell);
    Node(const Node& n);

    void addNeighbour(Node* n);

    vector<Node*>* getNeighbors();

    QPair<int,int> getLinkedCell();
};

#endif
