#include "ghost.h"

#include <QDebug>

Ghost::Ghost(QObject *parent, double x, double y, Graphe graphe, QPixmap* sprite) :
    Character(parent, x, y, sprite) {

    setMode(SCATTER);
    nbScatterCycle = 1;
    this->graphe = graphe;
    this->astar = Astar(graphe);
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

QList<Node*> Ghost::getPath(){
    return path;
}

void Ghost::calculateNewPath() {
    int x = this->pos().x() / Board::wallSize;
    int y = this->pos().y() / Board::wallSize;
    Node* start = graphe.getNode(QPair<int,int>(x,y));
    Node* end = graphe.getNode(getTarget());
    this->astar.calcul(start, end);
    this->path = astar.getPath();
}

// We consider that only adjacent cells can be part of the path
Direction Ghost::getDirectionFromPath(){
    QPair<int,int> nextCell = this->path.at(0)->getLinkedCell();
    int delta_x = nextCell.first - (this->pos().x() / Board::wallSize) ;
    int delta_y = nextCell.second - (this->pos().y() / Board::wallSize);
    Direction res;
    if (delta_x == 0){
        if (delta_y == 1) res = DOWN;
        else res = UP;
    }else {
        if (delta_x == 1) res = RIGHT;
        else res = LEFT;
    }
    return res;
}

// If we are not on an intersection
// We just want the only next possible Direction that is not
// the one we are coming from
Direction Ghost::getNextDirection(){
    int x = this->pos().x() / Board::wallSize;
    int y = this->pos().y() / Board::wallSize;
    Direction next = this->getDirection();
    if (Board::isIntersection(x,y)){
        this->lastIntersection = QPair<int,int>(x,y);
        this->calculateNewPath();
        next = this->getDirectionFromPath();
    } else {
        next = nextDirectionToTest(this->getDirection());
        while (!canMove(next) || isOppositeDirection(next)){
            next = nextDirectionToTest(next);
        }
    }
    return next;
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

Direction Ghost::nextDirectionToTest(Direction current){
    Direction next;
    switch (current){
        case UP:
            next = RIGHT;
            break;
        case RIGHT:
            next = DOWN;
            break;
        case DOWN:
            next = LEFT;
            break;
        case LEFT:
            next = UP;
            break;
    }
    return next;
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
