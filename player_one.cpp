#include <QGraphicsScene>
#include <QKeyEvent>
#include <iostream>
#include <string>
#include "player_one.h"
#include "bullet.h"
#include "player_two.h"

Player_one::Player_one(QGraphicsItem *parent): QGraphicsPixmapItem()
{
    /// get the current path and look for the background photo
    QList<QString> list = QDir::currentPath().split('/') ;
    list.pop_back();
    QString match = "new_copy";
    setPixmap(QPixmap(getPath(list, match) + "/tank.png"));
    setScale(scale_player_one);
}

void Player_one::keyPressEvent(QKeyEvent *event){

    if (pos().y() <= 0) {
        if (event->key() == Qt::Key_Down){
            setPos(x(),y()+10);
        }
    } else if (pos().y() >= Height - 50) {
        //std::cout << pos().y() << std::endl;
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
    if (event->key() == Qt::Key_Space) {
         Bullet *bullet = new Bullet();
         bullet->setPos(x() - 25, y() - 140);
         scene()->addItem(bullet);
    }
}

void Player_one::spawn() {
    Player_Two * enemy = new Player_Two();
    scene()->addItem(enemy);

}
