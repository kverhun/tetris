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

    void DisplayScore(int val);
    void DisplayLevel(int lvl);
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
    void onPause();
    void onResume();
    void onExit();

private slots:
    void on_newGameButton_clicked();

    void onStateUpdate(const State *);
    void on_pauseBtn_clicked();
    void on_endGameBtn_clicked();
    void on_exitBtn_clicked();
};

#endif // MAINWINDOW_H
