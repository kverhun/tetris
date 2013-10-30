#ifndef FIELD_H
#define FIELD_H

#include "FieldElement.h"
#include "Figure.h"

class Field
{
public:
    Field(int height=30, int width=15);
    void AddFigure (Figure* figure, int x, int y);

    bool IsFilled(int i, int j) {return _matrix[i][j].IsFilled();}
    Color GetColor(int i, int j) {return _matrix[i][j].GetColor();}

    int GetWidth() {return _width;}
    int GetHeigth() {return _height;}
    // method provides dropping bottom lines
    // rets: count of lines
    int Score();
private:

    vector<vector<FieldElement>> _matrix;
    int _width;
    int _height;
};

#endif // FIELD_H
