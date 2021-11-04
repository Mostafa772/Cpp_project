#ifndef BALL_H
#define BALL_H
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsScene>
#include <QtGui>

class Ball: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Ball();
    void keyPressEvent(QKeyEvent * event);

public slots:
    void move();

};
#endif // BALL_H
