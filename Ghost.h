#ifndef GHOST_H
#define GHOST_H

#include <stdlib.h>
#include "Character.h"

using namespace std;

class Ghost : Character {

private:
    bool affraid;
    bool chasing;

public:
	Ghost();

    bool isAffraid();

    bool isChasing();
};

#endif
