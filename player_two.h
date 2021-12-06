#ifndef PLAYER_TWO_H
#define PLAYER_TWO_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>
#include <QtGui>
#include "global.h"

class Player_Two: public QObject, public QGraphicsPixmapItem, public global{
    Q_OBJECT
public:
    Player_Two(QGraphicsItem * parent = 0);
    //void keyPressEvent(QKeyEvent * event);

public slots:
    void move();

private:
};

#endif // PLAYER_TWO_H
