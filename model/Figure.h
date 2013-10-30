#ifndef FIGURE_H
#define FIGURE_H

#include "FieldElement.h"

#include <vector>
using std::vector;


class Figure
{
public:
    Figure(FigurePrimitive primitive, Color color);
    Figure (const Figure&);
    bool IsFilled(int i, int j);
    Color GetColor (int i, int j);

    void RotateCW();
    void RotateCCW();

    int GetWidth() const {return _width;}
    int GetHeight() const {return _height;}

    FieldElement GetElement (int i, int j);

private:
    vector<vector<FieldElement>> _matrix;
    int _width;
    int _height;

};

#endif // FIGURE_H
