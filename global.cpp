//
// Created by mostafa on 05.12.2021.
//
#include "global.h"

QString global::getPath(QList<QString> list, QString match) {

  if (list.empty())
    return "";

  if (list[list.size() - 1] == match)
    return list.join('/');

  list.pop_back();

  return getPath(list, match);
}