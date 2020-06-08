#include "graphe.h"

Graphe::Graphe() {
    this->vertices = new vector<Node*>();
}

void Graphe::addNode(QPair<int,int> cell) {
    Node* n = new Node(cell);
    this->vertices->push_back(n);
}

void Graphe::addVertice(QPair<int,int> c1, QPair<int,int> c2) {
    Node* n1 = getNode(c1);
    Node* n2 = getNode(c2);
    n1->addNeighbour(n2);
}

vector<Node*>* Graphe::getNodes() {
    return this->vertices;
}

int Graphe::getInfinite() {
    if (this->infinite == -1){
        infinite = 1 + this->vertices->size();
    }
    return this->infinite;
}

Node* Graphe::getNode(QPair<int,int> cell) {
    for(Node* n : *vertices){
        if (n->getLinkedCell() == cell){
            return n;
        }
    }
    return NULL;
}
