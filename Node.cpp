#include "node.h"

Node::Node(QPair<int,int> cell){
    this->linkedCell = cell;
    this->neighbors = new vector<Node*>();
}

Node::Node(const Node& n) {
    this->neighbors = n.neighbors;
    this->linkedCell = n.linkedCell;
}

void Node::addNeighbour(Node* n) {
    this->neighbors->push_back(n);
}

vector<Node*>* Node::getNeighbors() {
    return this->neighbors;
}

QPair<int,int> Node::getLinkedCell(){
    return this->linkedCell;
}
