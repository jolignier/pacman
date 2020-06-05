#include "node.h"

Node::Node(const Node& n) {
    this->neighbors = n.neighbors;
    this->linkedCell = n.linkedCell;
    //this->graphe = n.graphe;
}

void Node::addNeighbour(QPair<int,int> cell) {
	// TODO - implement Node::addNeighbour
	throw "Not yet implemented";
}

void Node::getNeighbors() {
	// TODO - implement Node::getNeighbors
	throw "Not yet implemented";
}
