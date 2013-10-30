#ifndef GAMETIMER_H
#define GAMETIMER_H

#include <QObject>
#include <QTimer>

class GameTimer : public QObject
{
    Q_OBJECT
public:
    GameTimer();
    GameTimer(int level);
    int GetLevel();
    void IncLevel();
    void SetLevel(int lvl);
    void Start();
    void Pause();
    ~GameTimer() {delete _timer;}
private:
    QTimer* _timer;
    int _level;
    double _duration;

signals:
    void onMove();

private slots:
    void onTimeout();
};

#endif // GAMETIMER_H
