#include "presenter.h"

#include <QMessageBox>

Presenter::Presenter(IView *view)
{
    this->view = view;
    this->game = new GameController();

    QObject* qview = dynamic_cast<QObject*>(view);
    connect(qview, SIGNAL(onNewGame()), this->game, SLOT(onNewGame()));
    connect(qview, SIGNAL(onPause()), this->game, SLOT(onPause()));
    connect(qview, SIGNAL(onRotate()), this->game, SLOT(onRotate()));
    connect(qview, SIGNAL(onToLeft()), this->game, SLOT(onMoveLeft()));
    connect(qview, SIGNAL(onToRight()), this->game, SLOT(onMoveRight()));
    connect(qview, SIGNAL(onSpeedup()), this->game, SLOT(onSpeedup()));
    connect(qview, SIGNAL(onEndGame()), this->game, SLOT(onEnd()));

    connect(game, SIGNAL(onStateChanged()), this, SLOT(StateChange()));
    connect(game, SIGNAL(onGameEnd()), this, SLOT(EndGame()));
    // instead of speedup
    connect(qview, SIGNAL(onMakeMove()), this->game, SLOT(onMove()));

}



void Presenter::StartGame()
{
}

void Presenter::StateChange()
{
    if (game != nullptr)
        this->view->onStateUpdate(this->game->GetState());
    else
        view->onStateUpdate(nullptr);
}

void Presenter::EndGame()
{
    QMessageBox box;
    box.setText("Game over");
    box.exec();
}
