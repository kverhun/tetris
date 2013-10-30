#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "view/tetriswidget.h"

#include <QLayout>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setFocusPolicy(Qt::StrongFocus);
    ui->setupUi(this);
    this->tw = new TetrisWidget();
    this->tw->setGeometry(10,10, 301, 601);

    // adding TetrisWidget to Main Window's layout
    layout()->addWidget(this->tw);
    tw->repaint();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newGameButton_clicked()
{
    emit(onNewGame());
}

bool MainWindow::eventFilter(QObject*, QEvent *event)
{
    /*
    if (event->type() == QEvent::KeyPress)
    {
        switch (((QKeyEvent*)event)->key())
        {
        case Qt::Key_Down:
            emit(onSpeedup());
            break;
        case Qt::Key_Left:
            emit(onToLeft());
            break;
        case Qt::Key_Right:
            emit(onToRight());
            break;
        case Qt::Key_Up:
            emit(onRotate());
            break;
        }
    }
    */
    return true;
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    switch (event->key())
    {
    case Qt::Key_Down:
        emit(onMakeMove());
        break;
    case Qt::Key_Left:
        emit(onToLeft());
        break;
    case Qt::Key_Right:
        emit(onToRight());
        break;
    case Qt::Key_Up:
        emit(onRotate());
        break;
    }
    //Controller::Instance()->Upd();
}

void MainWindow::onStateUpdate(const State * st)
{
    this->tw->UpdateState(st);
    this->DisplayScore(st->GetScore());
    this->DisplayLevel(st->GetLevel());
    this->tw->repaint();
}


void MainWindow::on_pauseBtn_clicked()
{
    emit(onPause());
}

void MainWindow::on_endGameBtn_clicked()
{
    emit(onEndGame());
}

void MainWindow::on_exitBtn_clicked()
{
    emit(onExit());
}

void MainWindow::DisplayScore(int val)
{
    this->ui->scoreLabel->setText(QString::number(val));
}

void MainWindow::DisplayLevel(int lvl)
{
    this->ui->levelLable->setText(QString::number(lvl));
}
