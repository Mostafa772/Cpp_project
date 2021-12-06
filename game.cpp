#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "player_one.h"
#include "game.h"
#include "button.h"
#include "global.h"

Game::Game(QWidget *parent) {

    scene = new QGraphicsScene();
    QList<QString> list = QDir::currentPath().split('/');
    list.pop_back();
    // make the scene 800x600 instead of infinity by infinity (default)
    scene->setSceneRect(0, 0, Width, Height);

    setBackgroundBrush(QBrush(QImage(getPath(list)  + "/background.jpg")));
    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(Width, Height);


}

void Game::displayMainMenu()
{
    QGraphicsTextItem * titleText = new QGraphicsTextItem(QString("Cockroach Crasher"));
    QFont titleFont(font_);
    titleFont.setPointSize(font_size);
    titleText->setFont(titleFont);
    titleText->setDefaultTextColor(color_of_font_);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = title_y_pos;
    titleText->setPos(txPos, tyPos);
    scene->addItem(titleText);

    Button * playButton = new Button(QString("play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = play_button_y_pos;
    playButton->setPos(bxPos, byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem((playButton));

    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = quit_button_y_pos;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
}

void Game::start(){
    // clear the screen
    scene->clear();

    // test code TODO remove
    // create the player
    player = new Player_one();
    //player->setRect(0,0,50,50); // change the rect from 0x0 (default) to 100x100 pixels
    player->setPos(0, Height/2); // TODO generalize to always be in the middle bottom of screen
    //player->setPos(400,500);

    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // add the player to the scene
    scene->addItem(player);

    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    if (health->getHealth() <= 0) {
        qDebug() << "are we here \n";
        QCoreApplication::exit;
    }

    // spawn enemies
    int spowning_speed = 1;
    if (score->getScore() > 5) {
        spowning_speed = score->getScore()/5;
    }
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000/spowning_speed);


    show();
}
