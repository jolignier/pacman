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

    this->score = new ScoreManager(parent);
    connect(score, SIGNAL(currentScoreChanged()), this, SLOT(onScoreChanged()));
    connect(score, SIGNAL(scoresRetrieved()), this, SLOT(onScoresRetrieved()));

    this->gums = QVector<Gums*>();
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

    this->inky->setPlayer(this->player);
    this->inky->setBlinky(this->blinky);

    this->blinky->setPlayer(this->player);
}

void Game::displayBoard() {
    for (int i=0; i< Board::nbColumns; i++) {
        for (int j=0; j< Board::nbLines; j++) {
            if (board.isInky(i,j)) {
                int x=i*Board::wallSize; int y=j*Board::wallSize;
                inky = new Inky(this, x, y);
                inky->setZValue(3);
                this->scene->addItem(inky);

            } else if (board.isBlinky(i,j)) {
                int x=i*Board::wallSize; int y=j*Board::wallSize;
                blinky = new Blinky(this, x, y);
                blinky->setZValue(3);
                this->scene->addItem(blinky);

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

            } else if (board.isGum(i, j)) {
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
    // Lets all characters move
    player->nextFrame();
    inky->nextFrame();
    blinky->nextFrame();

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

    if (player->collidesWithItem(inky) || player->collidesWithItem(blinky)){
        qDebug() << "IM DYING";
    }
}

void Game::keyPressEvent(QKeyEvent *event) {
    this->player->keyPressEvent(event);
}

void Game::onSuperGumEaten(){
    qDebug() << "SUPER GUM ATE";
}

void Game::onScoreChanged(){
    ui->score->setNum(this->score->getCurrentScore());
}

void Game::onScoresRetrieved(){
    ui->highScore_score->setNum(this->score->getHighestScore().first);
}
