#ifndef GRAPHE_H
#define GRAPHE_H

class Graphe {

private:
	std::vector<Node> vertices;
	int infinite;

public:
	Graphe();

	void addNode(Cell c);

	void addVertice(Cell c1, Cell c2);

	void getNodes();

	void getInfinite();

	void getNode(Cell c);
};

#endif
