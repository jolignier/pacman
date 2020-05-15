#include "menu.h"
#include "ui_menu.h"
#include "mainwindow.h"

#include <QFile>
#include <QStringListModel>
#include <QTextStream>
#include <QTreeWidgetItem>

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
    ui->highScoresList->clear();
    QList<QPair<int, QString>>* scores = retrieveScores();
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

QList<QPair<int, QString>>* Menu::retrieveScores() {
    QFile inputFile(":/scores/scores_list");
    QList<QPair<int, QString>>* scoresList = new QList<QPair<int, QString>>();
    int nbScores = 0;

    if (inputFile.open(QIODevice::ReadOnly)) {
        QTextStream in(&inputFile);
        while (!in.atEnd() && nbScores<10 ) {
            QString line = in.readLine();
            QStringList splitted = line.split(",");
            QString name = splitted[0];
            int score = splitted[1].toInt();
            scoresList->append(QPair<int, QString>(score,name));
            nbScores++;
        }
        inputFile.close();
    }
    std::sort(scoresList->begin(), scoresList->end());
    std::reverse(scoresList->begin(), scoresList->end());
    return scoresList;
}
