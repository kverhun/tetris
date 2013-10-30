#ifndef FIELDELEMENT_H
#define FIELDELEMENT_H

#include "common.h"

class FieldElement
{
public:
    FieldElement():FieldElement(false, Color::none){}
    FieldElement(bool filled, Color color) {_filled=filled; _color=color;}

    void Fill() {_filled = true;}
    void Unfill() {_filled = false;}

    bool IsFilled() {return _filled;}
    Color GetColor() {return _color;}
    void SetColor(Color color) {_color = color;}
private:
    bool _filled;
    Color _color;
};


#endif // FIELDELEMENT_H
