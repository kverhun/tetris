#ifndef GAME_H
#define GAME_H

#include "State.h"

class Game
{
public:
    Game();
    void Start();
    void End();

    void MoveRigth();
    void MoveLeft();
    void Rotate();
    bool MakeMove();

    const State* GetState() {return _state;}
private:


    State* _state;

};

#endif // GAME_H
