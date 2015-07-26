#include "server.h"

server::server(QWidget *widget, QObject *parent) :QTcpServer(parent), _widget(widget)
{
    files.insert("test.cpp", "");
}

void server::textEdit(user *ho, QString file, editType type, int coursorStart, int coursorEnd, QString diff)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0 << user::editFile << (int)type << coursorStart << coursorEnd << diff;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));


    for (QList<user*>::iterator i = clients.begin(); i != clients.end(); ++i){ // Передаем изменения всем клиентам редактирующим текущий файл
        emit log ((*i)->getCurrentFile() +" "+ (*i)->getName() + " " + QString::number((int)(*i)->isAutchedUser()) + " " + QString::number(type)+" "+QString::number(coursorStart)+" "+QString::number(coursorEnd)+" "+diff);
        if ((*i)->isAutchedUser() && *i != ho && (*i)->getCurrentFile() == file){
            (*i)->getSocket()->write(block);
        }
    }
}

bool server::isNameUsed(QString n) const
{
    for (QList<user*>::const_iterator i = clients.begin(); i != clients.end(); ++i){ // Передаем изменения всем клиентам редактирующим текущий файл
        if ((*i)->isAutchedUser() && (*i)->getName() == n){
            return true;
        }
    }
    return false;
}

bool server::start(QHostAddress addr, qint16 port)
{
    if (!listen(addr, port))
    {
        qDebug() << "Server not started at" << addr << ":" << port;
        return false;
    }
    qDebug() << "Server started at" << addr << ":" << port;
    return true;
}

QString server::getUsers(user *without) const
{
    QString res;
    for (QList<user*>::const_iterator i = clients.begin(); i != clients.end(); ++i){
        if ((*i)->isAutchedUser() && *i != without){
            res += (*i)->getName() + ",";
        }
    }
    res.remove(res.length() - 1, 1);
    return res;
}

QString server::getFiles() const
{    QString res;
     for (QMap<QString, QString>::const_iterator i = files.begin(); i != files.end(); ++i){
             res += i.key() + ",";
     }
     res.remove(res.length() - 1, 1);
     return res;

}

void server::incomingConnection(qintptr handle)
{
    //создаем клиента
    user *client = new user(handle, this, this);
    connect(client, SIGNAL(removeUser(user*)), this, SLOT(onRemoveUser(user*)));
    clients.append(client);
}

void server::onRemoveUser(user *client)
{
    emit log (client->getName() + " - remove");

    clients.removeAt(clients.indexOf(client));
}
