#ifndef IVIEW_H
#define IVIEW_H

class IView
{
public:
    virtual void onNewGame() = 0;
    virtual void onToLeft() = 0;
    virtual void onToRight() = 0;
    virtual void onRotate() = 0;
    virtual void onSpeedup() = 0;
    virtual void onEndGame() = 0;
};

#endif // IVIEW_H
