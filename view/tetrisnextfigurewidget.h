#ifndef TETRISNEXTFIGUREWIDGET_H
#define TETRISNEXTFIGUREWIDGET_H

#include <QWidget>
#include <model/Figure.h>

class TetrisNextFigureWidget : public QWidget
{
public:
    void UpdateFigure(const Figure* figure) {_figure = figure; emit(paintEvent(nullptr));}
protected:
    void paintEvent(QPaintEvent *);
private:
    void PaintFigure();

    void DrawGrid(int hcount, int wcount);

    QColor ColorConvert (Color color);

    const Figure* _figure;
    const int _width = 6;
    const int _height = 6;
};

#endif // TETRISNEXTFIGUREWIDGET_H
