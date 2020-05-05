#ifndef GHOST_H
#define GHOST_H

class Ghost : Character {

private:
	boolean affraid;
	boolean chasing;

public:
	Ghost();

	boolean isAffraid();

	boolean isChasing();
};

#endif
