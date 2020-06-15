#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <QString>
#include <QRect>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QFrame>
#include <QDebug>
#include <QTimer>
#include <QResizeEvent>
#include <QVector>

#include "board.h"
#include "inky.h"
#include "blinky.h"
#include "pinky.h"
#include "clyde.h"
#include "player.h"
#include "gum.h"
#include "superGum.h"
#include "scoremanager.h"


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
    void displayBoard();
    void newGame();

    void keyPressEvent(QKeyEvent *event);

public slots:
    void update();
    void onScoreChanged();
    void onSuperGumEaten();
    void onScoresRetrieved();

private:
    Ui::Game *ui;

    bool playing;
    Board board;
    QGraphicsScene* scene;
    QTimer* timer;
    QVector<Gums*> gums;
    ScoreManager* score;

    Inky* inky;
    Blinky* blinky;
    Pinky* pinky;
    Clyde* clyde;

    Player* player;
};

#endif
