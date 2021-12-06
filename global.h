//
// Created by mostafa on 05.12.2021.
//

#ifndef NEW_COPY_GLOBAL_H
#define NEW_COPY_GLOBAL_H
#include <QGraphicsScene>
#include <QtGui>
#include <QString>
#include <QList>
#include <QScreen>

class global {
public:
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();

protected:
    QString getPath(QList<QString> list, QString match = "cockroach_killer");
    int Width = screenGeometry.width() - 200;
    int Height = screenGeometry.height() - 80;


    QString font_ = "comic sans";
    int font_size = 72;
    QString color_of_font_ = "Qt::black";
    int title_y_pos = 150;
    int play_button_y_pos = 275;
    int quit_button_y_pos = 350;

    double scale_player_one = 0.20;
    double scale_player_two = 0.25;
    double scale_bullet     = 0.25;

private:

};

#endif // NEW_COPY_GLOBAL_H
