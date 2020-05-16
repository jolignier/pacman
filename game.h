#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <QString>
#include <QRect>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QFrame>
#include <QDebug>
#include <QResizeEvent>

#include "board.h"

namespace Ui {
class Game;
}

class Game : public QFrame
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();

    bool hasWin();
    bool hasLost();
	void win();
	void lose();
	void displayMenu();
    void displayBoard(int cell_width, int cell_height);
    void newGame();

private:
    Ui::Game *ui;

    bool playing;
    Board board;
    QGraphicsScene* scene;
};

#endif
