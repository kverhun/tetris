#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "view/iview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public IView
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;


signals:
    void onNewGame();


private slots:
    void on_newGameButton_clicked();
};

#endif // MAINWINDOW_H
