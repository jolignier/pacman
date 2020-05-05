#ifndef ASTAR_H
#define ASTAR_H

class Astar {

private:
	Graphe graphe;
	Node starting;
	Node ending;
	vector<pair<Node, Integer>> distance;
	vector<pair<Node, boolean>> visited;
	vector<pair<Node, Node>> predecessor;

public:
	Astar(Graphe g);

	void initialize();

	Node getClosestNode();

	double getHeuristic();

	void calcul(Node starting, Node ending);

	void getPath();
};

#endif
