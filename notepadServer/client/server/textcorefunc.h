#ifndef TEXTCOREFUNC_H
#define TEXTCOREFUNC_H
#include "QString"
enum editType{
    inser,
    bacspace,
    delet
};

QString appdateText(const QString &t, editType type, int start, int end, QString diff);
QString getDiff(QString &t, int start, int end, editType &type);
#endif // TEXTCOREFUNC_H
