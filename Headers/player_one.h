#ifndef PLAYER_ONE_H
#define PLAYER_ONE_H
#include <QGraphicsScene>
#include <QtGui>
#include "ball.h"


class Player_one: public QGraphicsRectItem{
public:
    void keyPressEvent(QKeyEvent * event);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int Height = screenGeometry.height();
    int Width = screenGeometry.width();
};

#endif // PLAYER_ONE_H
