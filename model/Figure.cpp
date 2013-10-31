#include "Figure.h"

Figure::Figure(FigurePrimitive primitive, Color color)
{
    switch (primitive) {
    case FigurePrimitive::box:
        _width = 2;
        _height = 2;
        break;
    case FigurePrimitive::line:
        _width = 1;
        _height = 4;
        break;
    case FigurePrimitive::slide_l:
        _width = 3;
        _height = 2;
        break;
    case FigurePrimitive::slide_r:
        _width = 3;
        _height = 2;
        break;
    case FigurePrimitive::el_r:
        _width = 3;
        _height = 2;
        break;
    case FigurePrimitive::el_l:
        _width = 3;
        _height = 2;
        break;
    }

    _matrix = vector<vector<FieldElement>>(_height);
    for (auto i = 0; i < _height; ++i)
        _matrix[i] = vector<FieldElement>(_width);

    for (auto i = 0; i < _height; ++i)
        for (auto j = 0; j < _width; ++j)
            _matrix[i][j].SetColor(color);

    switch (primitive) {
    case FigurePrimitive::box:
        for (auto i = 0; i < _height; ++i)
            for (auto j = 0; j < _width; ++j)
                _matrix[i][j].Fill();
        break;
    case FigurePrimitive::line:
        for (auto i = 0; i < _height; ++i)
            for (auto j = 0; j < _width; ++j)
                _matrix[i][j].Fill();
        break;
    case FigurePrimitive::slide_l:
        _matrix[0][0].Fill();
        _matrix[0][1].Fill();
        _matrix[1][1].Fill();
        _matrix[1][2].Fill();
        break;
    case FigurePrimitive::slide_r:
        _matrix[0][1].Fill();
        _matrix[0][2].Fill();
        _matrix[1][1].Fill();
        _matrix[1][0].Fill();
        break;
    case FigurePrimitive::el_r:
        _matrix[0][2].Fill();
        _matrix[1][0].Fill();
        _matrix[1][1].Fill();
        _matrix[1][2].Fill();
        break;
    case FigurePrimitive::el_l:
        _matrix[0][0].Fill();
        _matrix[1][0].Fill();
        _matrix[1][1].Fill();
        _matrix[1][2].Fill();
        break;
    default:
        break;
    }
}

FieldElement Figure::GetElement(int i, int j)
{
    if (i < 0 || i >= _height || j < 0 || j >= _width)
        return FieldElement();
    else
        return _matrix[i][j];
}

Figure::Figure(const Figure & figure)
{
    this->_height = figure._height;
    this->_width = figure._width;
    this->_matrix = figure._matrix;
}

bool Figure::IsFilled(int i, int j) const
{
    if (i < 0 || i >= _height || j < 0 || j >= _width)
        return false;
    return _matrix[i][j].IsFilled();
}

Color Figure::GetColor(int i, int j) const
{
    if (i < 0 || i >= _height || j < 0 || j >= _width)
        return Color::none;
    return _matrix[i][j].GetColor();
}

void Figure::RotateCCW()
{
    int newHeight = _width;
    int newWidth = _height;
    vector<vector<FieldElement>> newMatrix = vector<vector<FieldElement>>(newHeight);
    for (auto i = 0; i < newHeight; ++i)
        newMatrix[i] = vector<FieldElement>(newWidth);
    for (auto i = 0; i < newHeight; ++i)
        for (auto j = 0; j < newWidth; ++j)
            newMatrix[i][j] = _matrix[j][_width-i-1];
    _matrix = newMatrix;
    _height = newHeight;
    _width = newWidth;
}

void Figure::RotateCW()
{
    int newHeight = _width;
    int newWidth = _height;
    vector<vector<FieldElement>> newMatrix = vector<vector<FieldElement>>(newHeight);
    for (auto i = 0; i < newHeight; ++i)
        newMatrix[i] = vector<FieldElement>(newWidth);
    for (auto i = 0; i < newHeight; ++i)
        for (auto j = 0; j < newWidth; ++j)
            newMatrix[i][j] = _matrix[_height-j-1][i];
    _matrix = newMatrix;
    _height = newHeight;
    _width = newWidth;
}



