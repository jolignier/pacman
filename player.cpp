#include "player.h"

#include <QDebug>

Player::Player(QObject *parent, double x, double y) :
    Character(parent, x, y, new QPixmap(":/sprites/player/pac"))
{
    this->nbLife = 3;
    this->superMode = false;
    this->setFutureDirection(NONE);
    this->rotateSprite(LEFT);

}

int Player::getNbLife() {
	return this->nbLife;
}

void Player::setNbLife(int nbLife) {
	this->nbLife = nbLife;
}

bool Player::isSuperMode(){
    return this->superMode;
}

void Player::onSuperGumEaten(){
    this->superMode = true;
    this->timer = new QTimer();
    this->timer->start(7000);
    this->connect(timer, SIGNAL(timeout()), this, SLOT(disableSuperMode()));
}

void Player::disableSuperMode(){
    this->superMode = false;
}

void Player::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
        case Qt::Key_Up:
            setFutureDirection(UP);
            break;
        case Qt::Key_Down:
            setFutureDirection(DOWN);
            break;
        case Qt::Key_Left:
            setFutureDirection(LEFT);
            break;
        case Qt::Key_Right:
            setFutureDirection(RIGHT);
            break;
    }
}

bool Player::canMove(Direction dir){
    bool res = Character::canMove(dir);
    int x = this->pos().x() / Board::wallSize;
    int y = this->pos().y() / Board::wallSize;
    if (dir == DOWN && Board::isGhostWall(x, y+1))
        res = false;

    return res;
}

void Player::rotateSprite(Direction dir) {

    double centerX = this->boundingRect().width()/2;
    double centerY = this->boundingRect().height()/2;
    QTransform transform = QTransform();
    transform.translate(centerX , centerY);

    switch (dir) {
        case UP:
            transform.rotate(-90);
            break;
        case DOWN:
            transform.rotate(90);
            break;
        case LEFT:
            transform.rotate(180);
            break;
        case RIGHT:
            transform.rotate(0);
            break;
        case NONE:
            break;
    }
    transform.translate( -centerX , -centerY );
    this->setTransform(transform);
}
