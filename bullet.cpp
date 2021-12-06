#include <iostream>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "bullet.h"
#include "player_two.h"
#include "game.h"

extern Game * game;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    QList<QString> list = QDir::currentPath().split('/');
    list.pop_back();
    //.scaled(4,4,Qt::IgnoreAspectRatio, Qt::SmoothTransformation
    QPixmap pic = QPixmap(getPath(list) + "/bullet.png");
    setPixmap(pic);
    setScale(scale_bullet);

    //setRect(0, 0, 5, 5);
    QTimer * timer = new QTimer();

    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);

}

void Bullet::move()
{
    // collision
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(Player_Two)) {
            game->score->increase();

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;

        }
    }
    setPos(x() + 10, y());
    if (pos().x() > Width) {
        scene()->removeItem(this);
        delete this;
    }
}
