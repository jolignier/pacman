#include "astar.h"

Astar::Astar(){}

Astar::Astar(Graphe g) {
    this->graphe = g;

    this->distance = QHash<Node*, int>();
    this->visited = QHash<Node*, bool>();
    this->predecessor = QHash<Node*, Node*>();

    this->path = QList<Node*>();

    this->starting = NULL;
    this->ending = NULL;
}

void Astar::initialize() {
    for (Node* n : graphe.getNodes()){
        this->visited.insert(n, false);
        this->distance.insert(n, graphe.getInfinite());
        this->predecessor.insert(n, NULL);
        this->path.clear();
    }
    this->distance.insert(starting, 0);
}

Node* Astar::getClosestNode() {
    int min = graphe.getInfinite()+1;
    Node* closest = NULL;
    for(Node* n : graphe.getNodes()){
        if (distance.value(n)< min && !visited.value(n)){
            min = distance.value(n);
            closest = n;
        }
    }
    return closest;
}

void Astar::calcul(Node* starting, Node* ending) {    
    this->starting = starting;
    this->ending = ending;
    this->initialize();

    int dist ;
    int distTemp = 0;
    Node* nodeTemp = starting;

    while(visited.values().contains(false)){
        visited.insert(nodeTemp, true);
        for (Node* neighbor : *nodeTemp->getNeighbors()){
            dist = distTemp + graphe.getLabel(nodeTemp->getLinkedCell(), neighbor->getLinkedCell());
            if (distance.value(neighbor) > dist && neighbor != starting) {
                distance.insert(neighbor, dist);
                predecessor.insert(neighbor, nodeTemp);
            }
        }

        nodeTemp = getClosestNode();
        if (nodeTemp != NULL){
            distTemp = distance.value(nodeTemp);
        }
    }

    Node* n = ending;
    while(n != NULL){
        this->path.push_front(n);
        n = predecessor.value(n);
    }
    if (!this->path.isEmpty()){
        path.pop_front();
    }
}

QList<Node*> Astar::getPath() {
    return this->path;
}
