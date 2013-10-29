#ifndef PRESENTER_H
#define PRESENTER_H

#include <QObject>

#include "view/iview.h"
#include "model/GameController.h"

class Presenter : public QObject
{
    Q_OBJECT
public:
    Presenter(IView* view);

private:

    IView* view;
    GameController* game;

private slots:
    void StartGame();


};

#endif // PRESENTER_H
