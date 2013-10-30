#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "view/tetriswidget.h"

#include <QLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
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
