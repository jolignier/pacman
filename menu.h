#ifndef MENU_H
#define MENU_H

#include <QFrame>
#include <scoremanager.h>

namespace Ui {
class Menu;
}

class Menu : public QFrame
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void play();
    void displayHelp();
    void displayHighScores();
    void displayMainMenu();

    void updateScores();

private:
    Ui::Menu *ui;
    ScoreManager* scoreManager;
};

#endif // Menu_H
