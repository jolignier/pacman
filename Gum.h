#ifndef GUM_H
#define GUM_H

#include "gums.h"

class Gum : public Gums {

public:
    Gum(int x, int y, int wallSize, QObject *parent);
    void eaten();
};

#endif
