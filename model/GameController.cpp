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
    //box.exec();
    _game->Start();
    emit(onStateChanged());
}

void GameController::onSpeedup()
{
    QMessageBox box;
    box.setText("speedUp");
    //box.exec();
    emit(onStateChanged());
}

void GameController::onRotate()
{
    _game->Rotate();
    QMessageBox box;
    box.setText("rotate");
    //box.exec();
    emit(onStateChanged());
}

void GameController::onMoveRight()
{
    QMessageBox box;
    box.setText("right");
    //box.exec();
    _game->MoveRight();
    emit(onStateChanged());
}

void GameController::onMoveLeft()
{
    QMessageBox box;
    box.setText("left");
    //box.exec();
    _game->MoveLeft();
    emit(onStateChanged());
}

void GameController::onMove()
{
    _game->MakeMove();
    emit(onStateChanged());
}
void GameController::onEnd()
{
    _game->End();
    emit(onStateChanged());
}
