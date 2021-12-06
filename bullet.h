#ifndef BALL_H
#define BALL_H
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>
#include <QtGui>
#include "global.h"

class Bullet: public QObject, public QGraphicsPixmapItem, public global {
    Q_OBJECT
public:
    Bullet(QGraphicsItem * parent = 0);
    //void keyPressEvent(QKeyEvent * event);

public slots:
    void move();

};
#endif // BALL_H
