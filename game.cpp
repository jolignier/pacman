#include "game.h"
#include "ui_game.h"
#include "mainwindow.h"
#include <QDebug>

Game::Game(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Game)
{
    this->scene = new QGraphicsScene();
    ui->setupUi(this);
    ui->scene->setScene(scene);
    this->timer = new QTimer();
    this->timer->start(35);
    score = new ScoreManager(parent);
    gums = QVector<Gums*>();
}

Game::~Game()
{
    delete ui;
}

bool Game::hasWin() {
    return false;
}

bool Game::hasLost() {
    return false;
}

void Game::win() {
	// TODO - implement Game::win
	throw "Not yet implemented";
}

void Game::lose() {
	// TODO - implement Game::lose
	throw "Not yet implemented";
}

void Game::displayMenu() {
	// TODO - implement Game::displayMenu
	throw "Not yet implemented";
}

void Game::newGame() {
    displayBoard();
    this->connect(timer, SIGNAL(timeout()), this, SLOT(update()));
}

void Game::displayBoard() {
    for (int i=0; i< Board::nbColumns; i++) {
        for (int j=0; j< Board::nbLines; j++) {

            if (board.isInky(i,j)) {
                int x=i*Board::wallSize; int y=j*Board::wallSize;
                QPixmap* sprite = new QPixmap(":/sprites/inky/up");
                inky = new Inky(this, x, y, sprite);
                inky->setZValue(1);
                this->scene->addItem(inky);

            } else if (board.isPlayer(i,j)) {
                int x=i*Board::wallSize; int y=j*Board::wallSize;
                player = new Player(this, x, y);
                player->setZValue(3);
                this->scene->addItem(player);

            } else if (board.isIntersection(i,j)) {
                int x=i*Board::wallSize; int y=j*Board::wallSize;
                QGraphicsRectItem* item = new QGraphicsRectItem(x,y,Board::wallSize,Board::wallSize);
                item->setBrush(QBrush(QColor(0,200,50)));
                item->setZValue(1);
                this->scene->addItem(item);

            }
            if (board.isGum(i, j)) {
                int x=i*Board::wallSize; int y=j*Board::wallSize;
                Gum *gum = new Gum(x, y, Board::wallSize, this);
                gum->setZValue(2);
                gums.push_back(gum);
                this->scene->addItem(gum);

            } else if (board.isSuperGum(i, j)) {
                int x=i*Board::wallSize; int y=j*Board::wallSize;
                SuperGum* supGum = new SuperGum(x, y, Board::wallSize, this);
                supGum->setZValue(2);
                gums.push_back(supGum);
                this->scene->addItem(supGum);
            }
        }
    }
}



void Game::update() {    
    player->nextFrame();
    inky->nextFrame();
    ui->scene->update();
    for (Gums* iter : gums) {
        if (player->collidesWithItem(iter)) {
            score->addPoints(iter->getPoints());
            this->scene->removeItem(iter);
            gums.removeOne(iter);
            iter->eaten();
            break;
        }        
    }
    qInfo() << score->getCurrentScore();
}

void Game::keyPressEvent(QKeyEvent *event) {
    this->player->keyPressEvent(event);
}

void Game::superGumEaten(){
    qDebug() << "SUPER GUM ATE";
}
