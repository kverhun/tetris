#ifndef TETRISWIDGET_H
#define TETRISWIDGET_H

#include <QWidget>

#include "model/State.h"

class TetrisWidget : public QWidget
{
public:
    void UpdateState(State* state) {_nextState = state; emit(paintEvent(nullptr));}
protected:
    void paintEvent(QPaintEvent *);
private:
    void PaintState(const State*);

    State* _currentState;
    State* _nextState;
};

#endif // TETRISWIDGET_H
