#include "ball.h"
#include <iostream>
#include <QTimer>
#include <QEvent>
#include <QGraphicsScene>

Ball::Ball()
{
    setRect(0, 0, 25, 25);
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(25);
}

void Ball::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        scene()->addItem(this);
        //setPos(x(),y());
    }
}

void Ball::move()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int Width = screenGeometry.width();
    bool going_left  = 1;
    bool going_right = 0;

    while (true) {
    if (going_left) {
        if (pos().x() <= 25) {

            going_left = false;
            going_right = true;
        }
        setPos(x() - 5, y());
    }
    if (going_right) {
        if (pos().x() >= 200) {
            going_left = true;
            going_right = false;
        }
        setPos(x() + 5, y());
    }
    }
}
