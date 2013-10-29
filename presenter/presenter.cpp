#include "presenter.h"


Presenter::Presenter(IView *view)
{
    this->view = view;
    this->game = new GameController();

    // connect here
}


void Presenter::StartGame()
{
    // game->start();
}
