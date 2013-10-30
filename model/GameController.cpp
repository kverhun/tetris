#include "GameController.h"

GameController::GameController()
{
    _game = new Game();
}

void GameController::onStart()
{
    _game->Start();
}

void GameController::onSpeedup()
{

}

void GameController::onRotate()
{
    _game->Rotate();
}

void GameController::onMoveRight()
{
    _game->MoveRigth();
}

void GameController::onMoveLeft()
{
    _game->MoveLeft();
}

void GameController::onMove()
{
    if (!_game->MakeMove())
    {
        this->onEnd();
    }
}
void GameController::onEnd()
{
    _game->End();
}
