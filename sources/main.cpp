#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "player_one.h"
#include <QGraphicsView>
#include "ball.h"
#include <QtGui>
#include <QColor>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int Height = screenGeometry.height();
    int Width = screenGeometry.width();

    QGraphicsScene * scene = new QGraphicsScene();

    Player_one* player_one = new Player_one();
    QGraphicsRectItem * player_two = new QGraphicsRectItem();
    Ball* ball = new Ball();
    ball -> setPos(Width/2, Height/2);
    scene->addItem(ball);
    player_one -> setRect(0, 0, 25, 100);
    player_two -> setRect(0, 0, 25, 100);

    scene -> addItem(player_one);
    scene -> addItem(player_two);

    player_one -> setFlag(QGraphicsItem::ItemIsFocusable);
    player_one -> setFocus();

    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    view->show();
    view->setFixedSize(Width - 200, Height);
    scene->setSceneRect(0, 0, Width - 200, Height);
    player_one->setPos(player_one->rect().width(), view->height()/2);
    player_two->setPos(view->width() - player_two->rect().width(), view->height()/2);
    return a.exec();

}
