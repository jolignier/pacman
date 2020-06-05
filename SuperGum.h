#ifndef SUPERGUM_H
#define SUPERGUM_H

#include "gum.h"

class SuperGum : public Gums {

Q_OBJECT

signals:
    void superEaten();

public:
    SuperGum(int x, int y, int wallSize, QObject *parent);
    void eaten() override;
};

#endif
