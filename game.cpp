#include "game.h"
#include "ui_game.h"
#include "mainwindow.h"

Game::Game(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Game)
{
    this->scene = new QGraphicsScene();
    ui->setupUi(this);
    ui->scene->setScene(scene);
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
    int cell_width = ui->scene->width() / board.getNbColumns();
    int cell_height = ui->scene->height() / board.getNbLines();
    this->displayBoard(cell_width, cell_height);
}

void Game::displayBoard(int cell_width, int cell_height) {
    for (int i=0; i< board.getNbLines(); i++) {
        for (int j=0; j< board.getNbColumns(); j++) {
            if (board.isWall(i,j)) {
                int y=i*cell_height; int x = j*cell_width;
                QGraphicsRectItem* item = new QGraphicsRectItem(x,y,cell_width,cell_height);
                item->setBrush(QBrush(QColor(255,153,204)));
                this->scene->addItem(item);
            }
        }
    }
}
