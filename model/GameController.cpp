#include "GameController.h"

#include <QMessageBox>

GameController::GameController()
{
    _isRunning = false;
    _game = new Game();
    _gameTimer = new GameTimer();
    connect(_gameTimer, SIGNAL(onMove()), this, SLOT(onMove()));
}

void GameController::onStart()
{
    //QMessageBox box;
    //box.setText("start");
    //box.exec();
    _isRunning = true;
    _game->Start();
    _gameTimer->Start();
    emit(onStateChanged());
}

void GameController::onNewGame()
{
    _game = new Game();
    _gameTimer = new GameTimer();
    connect(_gameTimer, SIGNAL(onMove()), this, SLOT(onMove()));
    this->onStart();
}

void GameController::onPause()
{
    if (_isRunning)
    {
        _isRunning = false;
        _gameTimer -> Pause();
    }
    else
    {
        _isRunning = true;
        _gameTimer -> Start();
    }
}

void GameController::onResume()
{
    _isRunning = true;
    _gameTimer->Start();
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
    this->updateLevel();
    emit(onStateChanged());
}
void GameController::onEnd()
{
    _game->End();
    _gameTimer->Pause();
    //delete _game;
    //delete _gameTimer;
    //_game = nullptr;
    //_gameTimer = nullptr;
    emit(onGameEnd());
    //QMessageBox box;
    //box.setText("Game over");
    //box.exec();
}

void GameController::updateLevel()
{
    int score = _game->GetScore();
    int lvl = score / 2000 + 1;
    this->_gameTimer->SetLevel(lvl);
    this->_game->SetLevel(lvl);
}
