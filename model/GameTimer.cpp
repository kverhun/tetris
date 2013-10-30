#include "GameTimer.h"

GameTimer::GameTimer()
{
    _timer = new QTimer(this);
    _level = 1;
    _duration = 500;
    connect(_timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
}

GameTimer::GameTimer(int level)
{
    _timer = new QTimer(this);
    _level = level;
    _duration = 600*(1-1/_level);
    connect(_timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
}

void GameTimer::IncLevel()
{
    ++_level;
    _duration = 600*(1-1/_level);
}

int GameTimer::GetLevel()
{
    return _level;
}

void GameTimer::onTimeout()
{
    emit(onMove());
    _timer->start(_duration);
}

void GameTimer::Start()
{
    _timer->start(_duration);
}

void GameTimer::Pause()
{
    _timer->stop();
}

void GameTimer::SetLevel(int lvl)
{
    _level = lvl;
}
