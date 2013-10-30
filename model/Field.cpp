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
            ++c;
            for (auto j = 0; j < _width; ++j)
                _matrix[i][j].Unfill();
        }
    }
    if (c > 0)
    {
        int lines = c;
        for (auto i = 0; i < _height; ++i)
        {
            if (lines <= 0)
                break;
            bool empty = true;
            for (auto j = 0; j < _width; ++j)
            {
                if (_matrix[_height - i - 1][j].IsFilled())
                {
                    empty = false;
                    break;
                }
            }
            if (empty)
            {
                for (auto k = i+1; k < _height; ++k)
                {
                    for (auto col = 0; col < _width; ++col)
                    {
                        _matrix[_height-1-k+1][col] = _matrix[_height-1-k][col];
                    }
                }
                --i;
                --lines;
            }
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
