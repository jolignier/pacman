#include "graphe.h"

#include <QDebug>

Graphe::Graphe() {
    this->vertices = vector<Node*>();
    this->labels = QHash<QPair<Node*,Node*>, int>();
    this->infinite = -1;
}

void Graphe::addNode(QPair<int,int> cell) {
    Node* n = new Node(cell);
    this->vertices.push_back(n);
}

void Graphe::addEdge(QPair<int,int> c1, QPair<int,int> c2) {
    Node* n1 = getNode(c1);    
    Node* n2 = getNode(c2);
    n1->addNeighbour(n2);
}

vector<Node*> Graphe::getNodes() {
    return this->vertices;
}

int Graphe::getLabel(QPair<int,int> c1, QPair<int,int> c2){
    QPair<Node*,Node*> pair = QPair<Node*,Node*>(getNode(c1), getNode(c2));
    return this->labels.value(pair);
}

void Graphe::setLabel(QPair<int,int> c1, QPair<int,int> c2, int value){
    QPair<Node*,Node*> pair = QPair<Node*,Node*>(getNode(c1), getNode(c2));
    this->labels.insert(pair, value);
}

int Graphe::getInfinite() { // Should return 323
    if (this->infinite == -1){
        this->infinite = 1;
        for(int val : labels.values()){
            this->infinite += val;
        }
    }
    return this->infinite;
}

Node* Graphe::getNode(QPair<int,int> cell) {
    for(Node* n : vertices){
        if (n->getLinkedCell() == cell){
            return n;
        }
    }
    return NULL;
}
