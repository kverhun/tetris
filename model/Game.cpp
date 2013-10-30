#include "Game.h"

Game::Game()
{
    _state = new State();
}

void Game::Start()
{

}

void Game::End()
{

}

bool Game::MakeMove()
{
   return _state->Move();
}

void Game::MoveLeft()
{
    _state->MoveLeft();
}

void Game::MoveRigth()
{
    _state->MoveRigth();
}

void Game::Rotate()
{
    _state->Rotate();
}
