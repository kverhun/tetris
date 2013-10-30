#include "presenter.h"

#include <QMessageBox>

Presenter::Presenter(IView *view)
{
    this->view = view;
    this->game = new GameController();

    QObject* qview = dynamic_cast<QObject*>(view);
    connect(qview, SIGNAL(onNewGame()), this->game, SLOT(onStart()));

    // connect here
}


void Presenter::StartGame()
{

}
