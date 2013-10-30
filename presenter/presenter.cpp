#include "presenter.h"

#include <QMessageBox>

Presenter::Presenter(IView *view)
{
    this->view = view;
    this->game = new GameController();

    QObject* qview = dynamic_cast<QObject*>(view);
    connect(qview, SIGNAL(onNewGame()), this->game, SLOT(onStart()));
    connect(qview, SIGNAL(onRotate()), this->game, SLOT(onRotate()));
    connect(qview, SIGNAL(onToLeft()), this->game, SLOT(onMoveLeft()));
    connect(qview, SIGNAL(onToRight()), this->game, SLOT(onMoveRight()));
    connect(qview, SIGNAL(onSpeedup()), this->game, SLOT(onSpeedup()));
    connect(qview, SIGNAL(onEndGame()), this->game, SLOT(onEnd()));
    // connect here
    connect(game, SIGNAL(onStateChanged()), this, SLOT(StateChange()));

    // temp
    connect(qview, SIGNAL(onMakeMove()), this->game, SLOT(onMove()));

}

/*
signals:
    void onNewGame();
    void onRotate();
    void onToLeft();
    void onToRigth();
    void onSpeedup();
    void onEndGame();
 */

void Presenter::StartGame()
{
}

void Presenter::StateChange()
{
    this->view->onStateUpdate(this->game->GetState());

}
