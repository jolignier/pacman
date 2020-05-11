#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "menu.h"
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
    qDebug() << "play";
}

void MainWindow::displayMainMenu() {
    this->setCentralWidget(new Menu());
}
