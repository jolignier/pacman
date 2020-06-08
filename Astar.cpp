#include "astar.h"

Astar::Astar(Graphe g) {
    this->graphe = g;
    QHash<QString, int> blyat;
}

void Astar::initialize() {
    for (Node* n : *graphe.getNodes()){
        visited.insert(n, false);
        distance.insert(n, graphe.getInfinite());
        predecessor.insert(n, NULL);
        path.clear();
    }
    distance.insert(starting, 0);
}

Node* Astar::getClosestNode() {
    int min = graphe.getInfinite()+1;
    Node* n = NULL;
    for(Node* n : *graphe.getNodes()){

    }
    return n;
}

double Astar::getHeuristic(Node* n) {
	// TODO - implement Astar::getHeuristic
	throw "Not yet implemented";
}

void Astar::calcul(Node* starting, Node* ending) {
	// TODO - implement Astar::calcul
	throw "Not yet implemented";
}

QList<Node*> Astar::getPath() {
    return this->path;
}
