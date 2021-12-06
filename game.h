#ifndef GAME_H
#define GAME_H

#include <iostream>
//#include <QMediaPlaylist>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player_one.h"
#include "score.h"
#include "health.h"
#include "global.h"

class Game: public QGraphicsView, public global{
    Q_OBJECT
public:

    Game(QWidget * parent=0);

    void displayMainMenu();

    QGraphicsScene * scene;
    Player_one * player;
    Score * score;
    Health * health;

public slots:
    void start();

private:
};

#endif // GAME_H
