#ifndef TETRISWIDGET_H
#define TETRISWIDGET_H

#include <QWidget>

#include "model/State.h"

class TetrisWidget : public QWidget
{
public:
    void UpdateState(const State* state) {_nextState = state; emit(paintEvent(nullptr));}
protected:
    void paintEvent(QPaintEvent *);
private:
    void PaintState(const State*);

    void DrawGrid(int hcount, int wcount);
    void DrawState();

    QColor ColorConvert (Color color);

    State* _currentState;
    const State* _nextState;
};

#endif // TETRISWIDGET_H
