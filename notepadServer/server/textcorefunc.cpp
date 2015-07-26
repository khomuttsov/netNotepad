#include "textcorefunc.h"



QString appdateText(const QString &t, editType type, int start, int end, QString diff)
{
    QString buffer;
    switch (type) {
    case inser:
        buffer = t.mid(0, start);
        buffer += diff;
        buffer += t.mid(end);
        break;
    case bacspace:
        buffer = t.mid(0, end) + t.mid(start);
    default:
        break;
    }
    return buffer;
}


QString getDiff(QString &t, int start, int end, editType &type)
{
    QString res;
    if (start < end){
        type = inser;
        res = t.mid(start, end - start);
    }
    else {
        type = bacspace;
    }
    return res;
}
