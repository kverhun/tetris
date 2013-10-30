#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "view/iview.h"
#include "view/tetriswidget.h"
#include "model/State.h"

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
    TetrisWidget* tw;

protected:
    bool eventFilter(QObject *, QEvent *);
    void keyPressEvent(QKeyEvent *);
signals:
    void onNewGame();
    void onRotate();
    void onToLeft();
    void onToRight();
    void onSpeedup();
    void onEndGame();
    //void onStateUpdate(State*);
    void onMakeMove();

private slots:
    void on_newGameButton_clicked();

    void onStateUpdate(const State *);
};

#endif // MAINWINDOW_H
