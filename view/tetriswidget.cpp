#include "tetriswidget.h"

#include <QPainter>

void TetrisWidget::paintEvent(QPaintEvent *)
{
    //if (_currentState == nullptr)
        PaintState(_nextState);
}

void TetrisWidget::PaintState(const State * state)
{
    QPainter painter(this);
    painter.fillRect(0,0,this->width(), this->height(), Qt::gray);
}
