#include "State.h"

#include <stdlib.h>

State::State()
{
    _field = new Field();
    _score = 0;
    _figureX = -1;
    _figureY = -1;
    _figure = new Figure(FigurePrimitive(rand()%4), Color(rand()%4));
    _nextFigure = new Figure(FigurePrimitive(rand()%4), Color(rand()%4));
}

void State::Start()
{
    _figureX = _field->GetWidth()/2;
    _figureY = 0;
}

bool State::Move()
{
    //return true;
    if (!isMoveEnded())
    {
        ++_figureY;
        return true;
    }
    else
    {
        _field->AddFigure(_figure, _figureX, _figureY);
        _figure = _nextFigure;
        _nextFigure = new Figure(FigurePrimitive(rand()%4), Color(rand()%4));
        if (!isDropAllowed())
            return false;
        _figureX = _field->GetWidth() / 2;
        _figureY = 0;
        _score += _field->Score();
    }
    return true;
}

void State::MoveLeft()
{
    if (isMoveLeftAllowed())
        --_figureX;
}

void State::MoveRight()
{
    if (isMoveRigthAllowed())
        ++_figureX;
}

void State::Rotate()
{
    if (isRotationAllowed())
        _figure->Rotate();
}

bool State::isDropAllowed()
{
    return true;
}

bool State::isMoveEnded()
{
    for (auto j = 0; j < _figure->GetWidth(); ++j)
    {
        int i = 0;
        while (! _figure->IsFilled(_figure->GetHeight() - 1 - i,j)) ++i;
        if (_field->IsFilled(_figureY+_figure->GetHeight()-i, _figureX+j)
                || (_figureY+_figure->GetHeight()-i > _field->GetHeigth()-1 ))
            return true;
    }
    return false;
}

bool State::isMoveLeftAllowed()
{
    return true;
}

bool State::isMoveRigthAllowed()
{
    return true;
}

bool State::isRotationAllowed()
{
    return true;
}

bool State::IsFilled(int i, int j) const
{
    if (_field->IsFilled(i,j))
        return true;
    if (_figure->IsFilled(i-_figureY, j - _figureX))
        return true;
    return false;
}

Color State::GetColor(int i, int j) const
{
    if (_field->IsFilled(i,j))
        return _field->GetColor(i,j);
    if (_figure->IsFilled(i-_figureY, j - _figureX))
        return _figure->GetColor(i-_figureY,j-_figureX);
    return none;
}



