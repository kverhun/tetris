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

    void SetLevel(int lvl) {_level = lvl;}
    int GetLevel () const {return _level;}
    int GetScore () const {return _score;}

    ~State() {delete _figure; delete _field; delete _nextFigure;}
private:

    bool isMoveEnded();
    bool isRotationAllowed();
    bool isMoveLeftAllowed();
    bool isMoveRightAllowed();
    bool isDropAllowed();

    Figure* _figure;
    int _figureX;
    int _figureY;
    Field* _field;

    // to be showed on window
    Figure* _nextFigure;

    int _score;
    void addScore(int lines);
    int _level;
};

#endif // STATE_H
