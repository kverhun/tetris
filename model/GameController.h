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
    int GetScore() {return _score;}
    void AddScore(int val) {_score += val;}
    ~GameController() {delete _game; delete _gameTimer;}
private:

    Game* _game;
    GameTimer* _gameTimer;

    bool _isRunning;
    int _score;

    void updateLevel();
signals:
    void onStateChanged();
    void onGameEnd();
private slots:
    void onNewGame();
    void onStart();
    void onEnd();
    void onMove();
    void onMoveLeft();
    void onMoveRight();
    void onRotate();
    void onSpeedup();
    //void Start();
    void onPause();
    void onResume();
};

#endif // GAMECONTROLLER_H
