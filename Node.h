#ifndef NODE_H
#define NODE_H

class Node {

private:
	std::vector<Node> neighbors;
	Graphe graphe;
	Cell linkedCell;

public:
	Node(Graphe g, cell c);

	void addNeighbour(Cell c);

	void getNeighbors();
};

#endif
