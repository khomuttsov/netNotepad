#include "textcorefunc.h"



QString updateText(const QString &t, editType type, int start, int end, QString diff)
{
    QString buffer;
    switch (type) {
    case INSERT:
        buffer = t.mid(0, start);
        buffer += diff;
        buffer += t.mid(start);
        break;
    case BACKSPACE:
        buffer = t.mid(0, end) + t.mid(start);
        break;
    case DELETE:
        buffer = t.mid(0, start) + t.mid(start+1);
        break;
    default:
        break;
    }
    return buffer;
}


QString getDiff(QString &t, int start, int end, editType &type)
{
    QString res;
    if (start < end){
        type = INSERT;
        res = t.mid(start, end - start);
    }
    else if (start == end){
        type = DELETE;
    }
    else {
        type = BACKSPACE;
    }
    return res;
}
