#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "menu.h"
#include "game.h"
#include <QFontDatabase>
#include <QDebug>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Add a custom font to the application
    QFontDatabase::addApplicationFont(":/fonts/emulogic");

    displayMainMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::play() {
    this->setCentralWidget(new Game());
    this->centralWidget()->show();
    qobject_cast<Game*>(this->centralWidget())->newGame();
}

void MainWindow::displayMainMenu() {
    this->setCentralWidget(new Menu());
}
