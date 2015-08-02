#include "server.h"

server::server(QObject *parent) :QTcpServer(parent)
{
    f = new QFile("date.txt");
    if (f->open(QIODevice::ReadOnly)){
       file = QString(f->readAll());
       f->close();
    }
}

void server::textEdit(user *ho, editType type, int coursorStart, int coursorEnd, int anchor, QString diff)
{
    file = updateText(file, type, coursorStart, coursorEnd, anchor, diff);
    f->open(QIODevice::WriteOnly);
    f->write(file.toUtf8());
    f->close();

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << user::editFile << (int)type << coursorStart << coursorEnd << anchor << diff;


    for (QList<user*>::iterator i = clients.begin(); i != clients.end(); ++i){ // Передаем изменения всем клиентам редактирующим текущий файл
        emit log ((*i)->getName() + " " + QString::number((int)(*i)->isAutchedUser()) + " " + QString::number(type)+" "+QString::number(coursorStart)+" "+QString::number(coursorEnd)+" "+diff);
        if ((*i)->isAutchedUser() && *i != ho){
            (*i)->getSocket()->write(block);
        }
    }
}

void server::textEdit(user *ho, QList<QByteArray> comands)
{
    int type;
    int coursorStart;
    int coursorEnd;
    int anchor;
    quint8 ct;
    QString diff;

    QList<QByteArray> comands1 = comands;
    QByteArray b;
    while(!comands1.isEmpty()){
        b = comands1.takeAt(0);
        QDataStream in1(&b, QIODevice::ReadOnly);
        in1 >> ct >> type >> coursorStart >> coursorEnd >> anchor >> diff;
        file = updateText(file, (editType)type, coursorStart, coursorEnd, anchor, diff);
    }
    f->open(QIODevice::WriteOnly);
    f->write(file.toUtf8());
    f->close();

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << user::list << comands;


    for (QList<user*>::iterator i = clients.begin(); i != clients.end(); ++i){ // Передаем изменения всем клиентам редактирующим текущий файл
        emit log ((*i)->getName() + " " + QString::number((int)(*i)->isAutchedUser()) + " " + QString::number(type)+" "+QString::number(coursorStart)+" "+QString::number(coursorEnd)+" "+diff);
        if ((*i)->isAutchedUser() && *i != ho){
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

void server::stop()
{
    for (QList<user*>::const_iterator i = clients.begin(); i != clients.end(); ++i){
        (*i)->send(user::disconnectd);
    }
    close();
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
