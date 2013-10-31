#include "tetrisnextfigurewidget.h"

#include <QPaintEvent>
#include <QPainter>

void TetrisNextFigureWidget::paintEvent(QPaintEvent * event)
{
    if (_figure == nullptr)
        return;
    this->PaintFigure();
}


void TetrisNextFigureWidget::DrawGrid(int hcount, int wcount)
{
    if (_figure == nullptr) return;
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

void TetrisNextFigureWidget::PaintFigure()
{
    QPainter painter(this);
    painter.fillRect(0,0,this->width(), this->height(), Qt::lightGray);

    this->DrawGrid(_height, _width);

    int h = this->height();
    int w = this->width();

    int atom_h = h / _height;
    int atom_w = w / _width;

    int x = (this->_width - _figure->GetWidth())/2;
    int y = (this->_height - _figure->GetHeight())/2;

    QPainter npainter(this);

    for (auto i = 0; i < _figure->GetHeight(); ++i)
        for (auto j = 0; j < _figure->GetWidth(); ++j)
        {
            if (_figure->IsFilled(i,j))
            {
                QRect rect = QRect((x+j)*atom_w+1, (y+i)*atom_h+1, atom_w-1, atom_h-1);
                QColor color = ColorConvert(_figure->GetColor(i,j));
                npainter.fillRect(rect, color);
            }
        }

}

QColor TetrisNextFigureWidget::ColorConvert(Color color)
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
