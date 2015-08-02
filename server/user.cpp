#include "user.h"

user::user(int desc, server *serv, QObject *parent) : QObject(parent)
{
    host = serv;
    isAutched = false;
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(desc);
    connect(socket, SIGNAL(connected()), this, SLOT(onConnect()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(onDisconnect()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError(QAbstractSocket::SocketError)));
}

void user::send(qint8 c)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << c;
    socket->write(block);
}

void user::sendUsers()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << usersList << host->getUsers(this) << host->file;
    socket->write(block);
}

void user::onConnect()
{

}

void user::onDisconnect()
{
    host->clients.removeAll(this);
    for (QList<user*>::iterator it = host->clients.begin();
         it != host->clients.end(); ++it){
        (*it)->sendUsers();
    }
}

void user::onReadyRead()
{
    QDataStream in(socket);

    //3 байт - команда серверу
    quint8 command;
    in >> command;
    //для неавторизованный пользователей принимается только команда "запрос на авторизацию"
    if (!isAutched && command != autch)
        return;

    switch(command)
    {
    //запрос на авторизацию
    case autch:{
        //считываем имя
        QString name;
        in >> name;

        //проверяем не используется ли имя
        if (host->isNameUsed(name))
        {
            //отправляем ошибку
            send(errorNaimIsUsed);
            return;
        }
        //авторизация пройдена
        this->name = name;
        isAutched = true;
        //отправляем новому клиенту список активных пользователей
        for (QList<user*>::iterator it = host->clients.begin();
             it != host->clients.end(); ++it){
            (*it)->sendUsers();
        }



        //сообщаем всем про нового ползователя
        // host->doSendToAllUserJoin(_name);
    }
        break;
    case list:{
        QList<QByteArray> textEditList;
        in >> textEditList;
        //отправляем его остальным
        host->textEdit(this, textEditList);

    }
        break;
    }

}

void user::onError(QAbstractSocket::SocketError e)
{
    //w нужна для обсвобождения памяти от QMessageBox (посредством *parent = &w)
    QWidget w;
    switch (e) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(&w, "Error", "The host was not found");
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(&w, "Error", "The connection was refused by the peer.");
        break;
    default:
        QMessageBox::information(&w, "Error", "The following error occurred: "+socket->errorString());
    }
    //тут вызовутся деструктор w и соответственно QMessageBox (по правилам с++)
}

