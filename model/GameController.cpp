#include "GameController.h"

#include <QMessageBox>

GameController::GameController()
{
    _game = new Game();
}

void GameController::onStart()
{
    QMessageBox box;
    box.setText("start");
    box.exec();
    _game->Start();
}

void GameController::onSpeedup()
{
    QMessageBox box;
    box.setText("speedUp");
    box.exec();
}

void GameController::onRotate()
{
    _game->Rotate();
    QMessageBox box;
    box.setText("rotate");
    box.exec();
}

void GameController::onMoveRight()
{
    QMessageBox box;
    box.setText("right");
    box.exec();
    _game->MoveRigth();
}

void GameController::onMoveLeft()
{
    QMessageBox box;
    box.setText("left");
    box.exec();
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
