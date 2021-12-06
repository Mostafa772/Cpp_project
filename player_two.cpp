#include <iostream>
#include <QDir>
#include <QTimer>
#include <QString>
#include <QGraphicsScene>
#include "player_two.h"
#include "game.h"

extern Game * game;

Player_Two::Player_Two(QGraphicsItem * parent): QObject(),  QGraphicsPixmapItem(parent)
{
    QList<QString> list = QDir::currentPath().split('/');
    list.pop_back();
    int random_number = rand() % (Height - 50);
    setPos(Width, random_number);
    setPixmap(QPixmap(getPath(list) + "/cockroach.png"));
    setScale(scale_player_two);
    QTimer * timer = new QTimer();

    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);

}

void Player_Two::move()
{
    setPos(x() - 5, y());
    if (pos().x() + pixmap().width() < 50) {
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
