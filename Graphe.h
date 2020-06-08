#ifndef GRAPHE_H
#define GRAPHE_H

#include <stdlib.h>
#include <vector>
#include <QPair>
#include <QVector>
#include "node.h"

using namespace std;

class Graphe {

private:
    vector<Node*>* vertices;
    int infinite;

public:
	Graphe();

    void addNode(QPair<int,int> cell);

    void addVertice(QPair<int,int> c1, QPair<int,int> c2);

    vector<Node*>* getNodes();

    int getInfinite();

    Node* getNode(QPair<int,int> cell);
};

#endif
