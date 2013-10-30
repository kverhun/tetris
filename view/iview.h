#ifndef IVIEW_H
#define IVIEW_H

#include "model/State.h"

class IView
{
public:
    virtual void onNewGame() = 0;
    virtual void onToLeft() = 0;
    virtual void onToRight() = 0;
    virtual void onRotate() = 0;
    virtual void onSpeedup() = 0;
    virtual void onEndGame() = 0;

    virtual void onPause() = 0;
    virtual void onResume() = 0;

    virtual void onExit() = 0;

    virtual void onStateUpdate(const State*) = 0;

    // temp
    virtual void onMakeMove() = 0;

    virtual void DisplayScore(int val) = 0;
    virtual void DisplayLevel(int lvl) = 0;
    virtual ~IView(){}

};

#endif // IVIEW_H
