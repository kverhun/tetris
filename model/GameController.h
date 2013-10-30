#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>

#include "Game.h"
#include "GameTimer.h"

class GameController : public QObject
{
    Q_OBJECT
public:
    GameController();
    const State* GetState() {return _game->GetState();}
    void newGame();
private:

    Game* _game;
    GameTimer* _gameTimer;
signals:
    void onStateChanged();
private slots:
    void onStart();
    void onEnd();
    void onMove();
    void onMoveLeft();
    void onMoveRight();
    void onRotate();
    void onSpeedup();
    //void Start();
    void onPause();
};

#endif // GAMECONTROLLER_H
