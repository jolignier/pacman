#include "menu.h"
#include "ui_menu.h"
#include "mainwindow.h"

#include <QTreeWidgetItem>
#include <scoremanager.h>

Menu::Menu(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    displayMainMenu();
    this->scoreManager = new ScoreManager(this);
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
}


void Menu::updateScores(){

    ui->highScoresList->clear();
    QList<QPair<int, QString>>* scores = scoreManager->getTop10();

    for(int i=0; i<scores->size(); i++) {
        QTreeWidgetItem *item = new QTreeWidgetItem(ui->highScoresList);
        item->setText(0,QString::number(i+1));
        item->setText(1,scores->at(i).second);

        item->setText(2,QString::number(scores->at(i).first));
        item->setTextAlignment(0, Qt::AlignHCenter | Qt::AlignVCenter);
        item->setTextAlignment(1, Qt::AlignHCenter | Qt::AlignVCenter);
        item->setTextAlignment(2, Qt::AlignHCenter | Qt::AlignVCenter);
    }
    for(int i = 1; i < 3; i++) {
        ui->highScoresList->header()->setSectionResizeMode(i,QHeaderView::Stretch);
        ui->highScoresList->resizeColumnToContents(i);
    }
}


void Menu::displayMainMenu() {
    this->ui->stackedWidget->setCurrentIndex(0);
}
