#ifndef GRAPHE_H
#define GRAPHE_H

#include <stdlib.h>
#include <vector>
#include <QPair>
#include <QVector>
#include <QHash>
#include "node.h"

using namespace std;

class Graphe {

private:
    vector<Node*> vertices;
    QHash<QPair<Node*,Node*>, int> labels;
    int infinite;

public:
	Graphe();

    void addNode(QPair<int,int> cell);

    void addEdge(QPair<int,int> c1, QPair<int,int> c2);

    vector<Node*> getNodes();

    int getInfinite();

    int getLabel(QPair<int,int> c1, QPair<int,int> c2);
    void setLabel(QPair<int,int> c1, QPair<int,int> c2, int value);

    Node* getNode(QPair<int,int> cell);
};

#endif
