#include "ghost.h"

#include <QDebug>

Ghost::Ghost(QObject *parent, double x, double y, QPixmap* sprite) :
    Character(parent, x, y, sprite) {

    setMode(SCATTER);    
    nbScatterCycle = 1;
    this->player = player;
    this->timer = new QTimer();
    this->timer->start(getModeChangeTime());
    this->connect(timer, SIGNAL(timeout()), this, SLOT(swapMode()));
}

// Schema of modes
// [LVL 1] Scatter (7s) -> chase(20s) -> scatter (7s) -> chase(20) -> scatter (5s) ....
// [LVL 2-4] Scatter (7s) -> chase(20s) -> scatter (7s) -> chase(20) -> scatter (5s) -> chase(infinite)
// [LVL 5+] Scatter (5s) -> chase(20s) -> scatter (5s) -> chase(20) -> scatter (5s) -> chase(infinite)
int Ghost::getModeChangeTime(){
    int res = 1000;
    if (nbScatterCycle < 3){
        if (mode == SCATTER){
            res = 7000;
        } else if (mode == CHASE){
            res = 20000;
        }
    } else {
        if (mode == SCATTER){
            res = 5000;
        } else if (mode == CHASE){
            res = 20000;
        }
    }
    return res;
}

bool Ghost::isAffraid() {
    return (mode == FRIGHTENED);
}

GhostMode Ghost::getMode(){
    return this->mode;
}

void Ghost::setMode(GhostMode mode){
    this->mode = mode;
}

void Ghost::onSpawn(){
    setMode(SCATTER);
    nbScatterCycle=1;
}

void Ghost::swapMode(){
    qDebug() << "I CHANGED MODE";
    if (mode == SCATTER) {
        setMode(CHASE);
    } else {
        setMode(SCATTER);
        nbScatterCycle++;
    }
    this->timer->setInterval(getModeChangeTime());
}


Player* Ghost::getPlayer(){
    return this->player;
}

void Ghost::setPlayer(Player* player){
    this->player = player;
}

// Return the euclidian distance between two coordinates
double Ghost::getDistance(QPair<int,int> a, QPair<int,int> b){
    return sqrt( pow(b.first - a.first,2) + pow(b.second - a.second ,2) );
}

void Ghost::calculateDirection(){
    QPair<int,int> target = getTarget();
    int x = this->pos().x() / Board::wallSize;
    int y = this->pos().y() / Board::wallSize;

    // Calculate distance for each adjacent cell
    double distance_left = getDistance(target, QPair<int,int>(x-1,y));
    double distance_right = getDistance(target, QPair<int,int>(x+1,y));
    double distance_up = getDistance(target, QPair<int,int>(x,y-1));
    double distance_down = getDistance(target, QPair<int,int>(x,y+1));

    // Bind them to their direction
    directionOrder[0] = QPair<double,Direction>(distance_left,LEFT);
    directionOrder[1] = QPair<double,Direction>(distance_right,RIGHT);
    directionOrder[2] = QPair<double,Direction>(distance_up,UP);
    directionOrder[3] = QPair<double,Direction>(distance_down,DOWN);

    // Sort them according to their distance
    sort(directionOrder, directionOrder+4);
}



// If we are not on an intersection
// We just want the only next possible Direction that is not
// the one we are coming from
Direction Ghost::getNextDirection(){
    int x = this->pos().x() / Board::wallSize;
    int y = this->pos().y() / Board::wallSize;
    calculateDirection();
    Direction next = directionOrder[0].second;
    if (Board::isIntersection(x,y)){
        lastIntersection = QPair<int,int>(x,y);
    }
    int i =1;
    while (isWall(next) || isOppositeDirection(next)){
        next = directionOrder[i].second;
        i++;
    }

    return next;
}

bool Ghost::isWall(Direction dir){
    bool res = false;
    int x = this->pos().x() / Board::wallSize;
    int y = this->pos().y() / Board::wallSize;
    switch (dir){
        case UP:
            res = Board::isWall(x,y-1);
            break;
        case RIGHT:
            res = Board::isWall(x+1,y);
            break;
        case DOWN:
            res = Board::isWall(x,y+1);
            break;
        case LEFT:
            res = Board::isWall(x-1,y);
            break;
    }
    return res;
}

bool Ghost::isOppositeDirection(Direction dir){
    bool res = false;
    switch (this->getDirection()){
        case UP:
            res = (dir == DOWN);
            break;
        case RIGHT:
            res = (dir == LEFT);
            break;
        case DOWN:
            res = (dir == UP);
            break;
        case LEFT:
            res = (dir == RIGHT);
            break;
    }
    return res;
}

bool Ghost::isNotLastIntersection(int x, int y){
    return !(lastIntersection.first == x && lastIntersection.second ==y);
}

void Ghost::nextFrame(){
    int x = this->pos().x() / Board::wallSize;
    int y = this->pos().y() / Board::wallSize;

    if (!canMove(this->getDirection()) || (Board::isIntersection(x,y) && isNotLastIntersection(x,y))){
        this->setFutureDirection(getNextDirection());
    }
    Character::nextFrame();
}
