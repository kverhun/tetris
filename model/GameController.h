#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>

#include "Game.h"

class GameController : public QObject
{
    Q_OBJECT
public:
    GameController();
private:

    Game* _game;

private slots:
    void onStart();
    void onEnd();
    void onMove();
    void onMoveLeft();
    void onMoveRight();
    void onRotate();
    void onSpeedup();
};

#endif // GAMECONTROLLER_H
