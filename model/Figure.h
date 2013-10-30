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
    bool IsFilled(int i, int j) {return _matrix[i][j].IsFilled();}
    bool GetColor (int i, int j) {return _matrix[i][j].GetColor();}
    void Rotate();

    int GetWidth() {return _width;}
    int GetHeight() {return _height;}

    FieldElement GetElement (int i, int j);

private:
    vector<vector<FieldElement>> _matrix;
    int _width;
    int _height;

};

#endif // FIGURE_H
