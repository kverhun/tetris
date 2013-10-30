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
    painter.fillRect(0,0,this->width(), this->height(), Qt::lightGray);

    if (_nextState == nullptr) return;
    this->DrawGrid(state->GetHeight(), state->GetWidth());
    this->DrawState();
}

void TetrisWidget::DrawGrid(int hcount, int wcount)
{
    if (_nextState == nullptr) return;
    QPainter painter(this);
    int h = this->height();
    int w = this->width();

    int atom_h = h / hcount;
    int atom_w = w / wcount;

    for (auto i = 0; i <= hcount; ++i)
        painter.drawLine(0, i*atom_h, w, i*atom_h);
    for (auto i = 0; i <= wcount; ++i)
        painter.drawLine(i*atom_w, 0, i*atom_w, h);

}

void TetrisWidget::DrawState()
{
    if (_nextState == nullptr)
        return;

    int hcount = _nextState->GetHeight();
    int wcount = _nextState->GetWidth();

    int h = this->height();
    int w = this->width();

    int atom_h = h / hcount;
    int atom_w = w / wcount;

    QPainter painter(this);

    for (auto i = 0; i < _nextState->GetHeight(); ++i)
        for (auto j = 0; j < _nextState->GetWidth(); ++j)
        {
            if (_nextState->IsFilled(i,j))
            {
                QRect rect = QRect(j*atom_w+1, i*atom_h+1, atom_w-1, atom_h-1);
                QColor color = ColorConvert(_nextState->GetColor(i,j));
                painter.fillRect(rect, color);
            }
        }

}

QColor TetrisWidget::ColorConvert(Color color)
{
    QColor qcolor = Qt::black;
    switch (color)
    {
    case red:
        qcolor = Qt::red;
        break;
    case green:
        qcolor = Qt::darkGreen;
        break;
    case blue:
        qcolor = Qt::blue;
        break;
    case yellow:
        qcolor = Qt::yellow;
        break;
    }
    return qcolor;
}
