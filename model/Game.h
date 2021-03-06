#ifndef GAME_H
#define GAME_H

#include "State.h"

class Game
{
public:
    Game();
    void Start();
    void End();

    void MoveRight();
    void MoveLeft();
    void Rotate();
    bool MakeMove();

    bool IsRunning() const {return _isRunning;}

    const State* GetState() {return _state;}
    int GetScore () const;
    void SetLevel(int lvl);

    ~Game() {delete _state;}
private:

    bool _isRunning;
    State* _state;

};

#endif // GAME_H
