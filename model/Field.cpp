#include "Field.h"

Field::Field(int height, int width)
{
    _height = height;
    _width = width;
    _matrix = vector<vector<FieldElement>>(_height);
    for (auto i = 0; i < _height; ++i) _matrix[i]=vector<FieldElement>(_width);
}

void Field::AddFigure(Figure* figure, int x, int y)
{
    for (auto i = 0; i < figure->GetHeight(); ++i)
        for (auto j = 0; j < figure->GetWidth(); ++j)
        {
            if (figure->IsFilled(i,j))
            _matrix[y+i][x+j] = figure->GetElement(i,j);
        }
}

int Field::Score()
{
    int c = 0;

    for (auto i = 0; i < _height; ++i)
    {
        bool full = true;
        for (auto j = 0; j < _width; ++j)
        {
            if (!_matrix[i][j].IsFilled())
            {
                full = false;
                break;
            }
        }
        if (full)
        {
        //
        }
    }
    return c;
}

bool Field::IsFilled(int i, int j)
{
    if (i < 0 || i >= _height || j < 0 || j >= _width)
        return false;
    return _matrix[i][j].IsFilled();
}

Color Field::GetColor(int i, int j)
{
    if (i < 0 || i >= _height || j < 0 || j >= _width)
        return none;
    return _matrix[i][j].GetColor();
}
