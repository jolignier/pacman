#ifndef MENU_H
#define MENU_H

#include <QFrame>

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

private:
    Ui::Menu *ui;    
    QList<QPair<int, QString>>* retrieveScores();
};

#endif // Menu_H
