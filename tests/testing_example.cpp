//
// Created by mostafa on 05.12.2021.
//
#include <QtTest/QtTest>
#include "bullet.h"

class testing_example: public QObject
{
  Q_OBJECT
private slots:
  void toUpper();
};

void testing_example::toUpper()
{
  QString str = "Hello";
  QVERIFY(str.toUpper() == "HELLO");
}

QTEST_MAIN(testing_example)
#include "testing_example.moc"