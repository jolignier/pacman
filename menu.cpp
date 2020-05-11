#include "menu.h"
#include "ui_menu.h"
#include "mainwindow.h"

#include <QDebug>
#include <QStringListModel>

Menu::Menu(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);

    displayMainMenu();
}

Menu::~Menu()
{
    delete ui;
}

void Menu::play() {
    qobject_cast<MainWindow*>(this->parent())->play();
}

void Menu::displayHelp() {
    this->ui->stackedWidget->setCurrentIndex(1);
}

void Menu::displayHighScores() {    
    this->ui->stackedWidget->setCurrentIndex(2);

    QStringList* scores = new QStringList();
    for (int i=0; i<10; i++) {
        scores->append("YOLO : " + QString::number(i+1));
    }
    ui->highScoresList->setModel(new QStringListModel(*scores, NULL));
}

void Menu::displayMainMenu() {
    this->ui->stackedWidget->setCurrentIndex(0);
}
