#include "player_one.h"
#include <QGraphicsScene>
#include <QKeyEvent>

void Player_one::keyPressEvent(QKeyEvent *event){
    if (pos().y() <= 0) {
        if (event->key() == Qt::Key_Down){
                setPos(x(),y()+10);
        }
    } else if (pos().y() >= Height - 150) {
        if (event->key() == Qt::Key_Up){
                setPos(x(),y()-10);
        }
    }
    else if (event->key() == Qt::Key_Up){
        setPos(x(),y()-10);
    }
    else if (event->key() == Qt::Key_Down){
        setPos(x(),y()+10);
    }
}
