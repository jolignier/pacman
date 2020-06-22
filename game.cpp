#include "game.h"
#include "ui_game.h"
#include "mainwindow.h"

#include <QDebug>
#include <QSound>

Game::Game(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Game)
{
    this->scene = new QGraphicsScene();
    ui->setupUi(this);
    ui->scene->setScene(scene);
    this->timer = new QTimer();
    this->timer->start(35);

    this->score = new ScoreManager(parent);
    connect(score, SIGNAL(currentScoreChanged()), this, SLOT(onScoreChanged()));
    connect(score, SIGNAL(scoresRetrieved()), this, SLOT(onScoresRetrieved()));

    this->gums = QVector<Gums*>();
    this->ghosts = QVector<Ghost*>();
}

Game::~Game()
{
    delete ui;
}

bool Game::hasWin() {
    return (gums.size() < 1);
}

bool Game::hasLost() {
    return (player->getNbLife() <1);
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
    qobject_cast<MainWindow*>(this->parent())->displayMainMenu();
}

void Game::newGame() {
    displayBoard();
    this->connect(timer, SIGNAL(timeout()), this, SLOT(update()));

    this->inky->setBlinky(this->blinky);
    this->inky->setPlayer(this->player);
    this->blinky->setPlayer(this->player);
    this->pinky->setPlayer(this->player);
    this->clyde->setPlayer(this->player);

    this->ghosts.push_back(inky);
    this->ghosts.push_back(pinky);
    this->ghosts.push_back(blinky);
    this->ghosts.push_back(clyde);
}

void Game::displayBoard() {
    for (int i=0; i< Board::nbColumns; i++) {
        for (int j=0; j< Board::nbLines; j++) {
            if (board.isWall(i,j)) {
                int x=i*Board::wallSize; int y=j*Board::wallSize;
                QGraphicsRectItem* item = new QGraphicsRectItem(x,y,Board::wallSize,Board::wallSize);
                item->setBrush(QBrush(QColor("transparent")));
                this->scene->addItem(item);

            } else if (board.isInky(i,j)) {
                int x=i*Board::wallSize; int y=j*Board::wallSize;
                inky = new Inky(this, x, y);
                inky->setZValue(3);
                this->scene->addItem(inky);

            } else if (board.isBlinky(i,j)) {
                int x=i*Board::wallSize; int y=j*Board::wallSize;
                blinky = new Blinky(this, x, y);
                blinky->setZValue(3);
                this->scene->addItem(blinky);

            } else if (board.isPinky(i,j)) {
                int x=i*Board::wallSize; int y=j*Board::wallSize;
                pinky = new Pinky(this, x, y);
                pinky->setZValue(3);
                this->scene->addItem(pinky);

            } else if (board.isClyde(i,j)) {
                int x=i*Board::wallSize; int y=j*Board::wallSize;
                clyde = new Clyde(this, x, y);
                clyde->setZValue(3);
                this->scene->addItem(clyde);

            } else if (board.isPlayer(i,j)) {
                int x=i*Board::wallSize; int y=j*Board::wallSize;
                player = new Player(this, x, y);
                player->setZValue(3);
                this->scene->addItem(player);

            }
            if (board.isIntersection(i,j)) {
                int x=i*Board::wallSize; int y=j*Board::wallSize;
                QGraphicsRectItem* item = new QGraphicsRectItem(x,y,Board::wallSize, Board::wallSize);
                item->setBrush(QBrush(QColor(0,200,50, 200)));
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

    // Lets move all characters
    player->nextFrame();

    inky->nextFrame();
    blinky->nextFrame();
    pinky->nextFrame();
    clyde->nextFrame();

    ui->scene->update();

    // Watch for gum collisions with player
    for (Gums* iter : gums) {
        if (player->collidesWithItem(iter)) {
            score->addPoints(iter->getPoints());
            this->scene->removeItem(iter);
            gums.removeOne(iter);
            iter->eaten();
            break;            
        }
    }

    // Ghost collision with player
    for (Ghost* g : this->ghosts){
        if (player->collidesWithItem(g)){
            if (player->isSuperMode()){
                if (g->isAffraid()){
                    this->score->addPoints(this->player->getScoreMultiplier()*200);
                    qDebug() << " EARNED : " << this->player->getScoreMultiplier()*200 << " POINTS";
                    this->player->increaseScoreMultiplier();
                    g->setMode(EATEN);
                    g->rotateSprite(g->getDirection());
                }
            } else {
                qDebug() << "IM DYING";
            }
        }
    }
}

void Game::keyPressEvent(QKeyEvent *event) {
    qDebug() << "KEY PRESSED";
    this->player->keyPressEvent(event);
}

void Game::onSuperGumEaten(){
    qDebug() << "SUPER GUM ATE";
    this->player->onSuperGumEaten();
    this->inky->onSuperGumEaten();
    this->pinky->onSuperGumEaten();
    this->blinky->onSuperGumEaten();
    this->clyde->onSuperGumEaten();
}

void Game::onScoreChanged(){
    ui->score->setNum(this->score->getCurrentScore());
}

void Game::onScoresRetrieved(){
    ui->highScore_score->setNum(this->score->getHighestScore().first);
}
