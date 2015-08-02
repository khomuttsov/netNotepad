#include "textcorefunc.h"



QString updateText(const QString &t, editType type, int start, int end, int anchor, QString diff)
{
    QString buffer;
    switch (type) {
    case INSERT:
        if (anchor != -1){
            if (anchor > start){
                buffer = t.mid(0, start) + diff + t.mid(anchor);
            }
            else{
                buffer = t.mid(0, anchor) + diff + t.mid(start);
            }
        }
        else{
            buffer = t.mid(0, start);
            buffer += diff;
            buffer += t.mid(start);
        }
        break;
    case BACKSPACE:
        if (anchor != -1){
            if (anchor > start){
                buffer = t.mid(0, end) + t.mid(anchor);
            }
            else{
                buffer = t.mid(0, anchor) + t.mid(start);
            }
        }
        else
            buffer = t.mid(0, end) + t.mid(start);
        break;
    case DELETE:
        if (anchor != -1){
            if (anchor > start){
                buffer = t.mid(0, start) + t.mid(anchor);
            }
            else{
                buffer = t.mid(0, anchor) + t.mid(start);
            }
        }
        else
            buffer = t.mid(0, start) + t.mid(start+1);
        break;
    default:
        break;
    }
    return buffer;
}


QString getDiff(QString &t, int start, int end, int anchor, editType &type)
{
    qDebug() << anchor;
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
