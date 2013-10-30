#ifndef STATE_H
#define STATE_H

#include "Field.h"
#include "Figure.h"

class State
{
public:
    State();
    void Start();
    bool Move();
    void MoveLeft();
    void MoveRight();
    void Rotate();

    int GetHeight() const {return _field->GetHeigth();}
    int GetWidth() const {return _field->GetWidth();}

    bool IsFilled (int i, int j) const;
    Color GetColor(int i, int j) const;

private:
    int GetScore () {return _score;}
    bool isMoveEnded();
    bool isRotationAllowed();
    bool isMoveLeftAllowed();
    bool isMoveRigthAllowed();
    bool isDropAllowed();

    Figure* _figure;
    int _figureX;
    int _figureY;
    Field* _field;

    // to be showed on window
    Figure* _nextFigure;

    int _score;
};

#endif // STATE_H
