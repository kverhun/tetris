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
    ~Presenter() {delete game; delete view;}
private:

    IView* view;
    GameController* game;

private slots:
    void StartGame();

    void StateChange();
    void EndGame();


};

#endif // PRESENTER_H
