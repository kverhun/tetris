#include "State.h"

#include <stdlib.h>

State::State()
{
    _field = new Field();

    _figureX = -1;
    _figureY = -1;
    _figure = new Figure(FigurePrimitive(rand()%4), Color(rand()%4));
    _figure = new Figure(FigurePrimitive(rand()%4), Color(rand()%4));
}

void State::Start()
{
    _figureX = _field->GetWidth()/2;
    _figureY = 0;
}

bool State::Move()
{
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

void State::MoveRigth()
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
    return true;
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
