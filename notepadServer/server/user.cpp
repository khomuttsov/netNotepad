#include "user.h"

user::user(int desc, server *serv, QObject *parent) : QObject(parent)
{
    host = serv;
    isAutched = false;
    blockSize = 0;
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(desc);
    currentFile = "test.cpp";
    connect(socket, SIGNAL(connected()), this, SLOT(onConnect()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(onDisconnect()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError(QAbstractSocket::SocketError)));
}

void user::send(qint8 c)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;
    out << c;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    socket->write(block);
}

void user::sendUsers()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;
    out << usersList << host->getUsers(this) << host->getFiles();
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    socket->write(block);
}

void user::sendFiles()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;
    out << filesList << host->getFiles();
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
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
    //если считываем новый блок первые 2 байта это его размер
    if (blockSize == 0) {
        //если пришло меньше 2 байт ждем пока будет 2 байта
        if (socket->bytesAvailable() < (int)sizeof(quint16))
            return;
        //считываем размер (2 байта)
        in >> blockSize;
        qDebug() << "Размер блока:" << blockSize;
    }
    //ждем пока блок прийдет полностью
    if (socket->bytesAvailable() < blockSize)
        return;
    else
        blockSize = 0; //можно принимать новый блок

    //3 байт - команда серверу
    quint8 command;
    in >> command;
    qDebug() << "Код команды:" << command;
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
    case editFile:{
        QString diff;
        int type, start, end;
        in >> type >> start >> end >> diff;
        //отправляем его остальным
        host->textEdit(this, currentFile, (editType) type, start, end, diff);

    }
        break;
    case chaingCurFile:{
        QString file;
        in >> file;
        //отправляем его остальным
        currentFile = file;
        emit host->log(name + " " + file);
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

