#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>

namespace Ui {
class menuWindow;
}

class menuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit menuWindow(QWidget *parent = nullptr);
    ~menuWindow();

private:
    Ui::menuWindow *ui;
};

#endif // MENUWINDOW_H
