#include "Game.h"

Game::Game()
{
    _state = new State();
}

void Game::Start()
{
    _isRunning = true;
}

void Game::End()
{
    _isRunning = false;

}

bool Game::MakeMove()
{
   if (!_isRunning) return false;
   return _state->Move();
}

void Game::MoveLeft()
{
    if (!_isRunning) return;
    _state->MoveLeft();
}

void Game::MoveRight()
{
    if (!_isRunning) return;
    _state->MoveRight();
}

void Game::Rotate()
{
    if (!_isRunning) return;
    _state->Rotate();
}

int Game::GetScore() const
{
    return _state->GetScore();
}
void Game::SetLevel(int lvl)
{
    _state->SetLevel(lvl);
}
