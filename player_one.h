#ifndef PLAYER_ONE_H
#define PLAYER_ONE_H
#include <QGraphicsScene>
#include <QtGui>
#include "bullet.h"
#include "global.h"


class Player_one: public QObject, public QGraphicsPixmapItem, public global{
    Q_OBJECT
public:
    Player_one(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);

public slots:
    void spawn();

private:
};

#endif // PLAYER_ONE_H
