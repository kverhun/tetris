#include "GameController.h"

#include <QMessageBox>

GameController::GameController()
{
    _game = new Game();
    _gameTimer = new GameTimer();
    connect(_gameTimer, SIGNAL(onMove()), this, SLOT(onMove()));
}

void GameController::onStart()
{
    QMessageBox box;
    box.setText("start");
    //box.exec();
    _game->Start();
    _gameTimer->Start();
    emit(onStateChanged());
}

void GameController::newGame()
{
    _game = new Game();
    _gameTimer = new GameTimer();
    connect(_gameTimer, SIGNAL(onMove()), this, SLOT(onMove()));
    this->onStart();
}

void GameController::onPause()
{
    _gameTimer->Pause();
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
    if (!_game->MakeMove())
    {
        this->onEnd();
    }
    emit(onStateChanged());
}
void GameController::onEnd()
{
    _game->End();
    _gameTimer->Pause();
    emit(onStateChanged());
    QMessageBox box;
    box.setText("Game over");
    box.exec();
}
