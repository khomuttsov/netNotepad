#ifndef USER_H
#define USER_H

#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QDebug>
#include <QMessageBox>

#include "server.h"

class server;
class user : public QObject
{
    Q_OBJECT
    friend class server;
public:
    explicit user(int desc, server *serv, QObject *parent = 0);
    inline QString getCurrentFile() const { return currentFile; }
    inline bool isAutchedUser() const { return isAutched; }
    inline QTcpSocket *getSocket() const { return socket; }
    inline QString getName() const { return name; }
    void send(qint8 c);
private:
    QTcpSocket *socket;
    server *host;
    QString name;
    QString currentFile;
    qint16 blockSize;
    bool isAutched;

    void sendUsers();
    void sendFiles();
private slots:
    void onConnect();
    void onDisconnect();
    void onReadyRead();
    void onError(QAbstractSocket::SocketError e);


public:
    static const quint8 autch = 1;
    static const quint8 editFile = 2;
    static const quint8 usersList = 3;
    static const quint8 filesList = 4;
    static const quint8 chaingCurFile = 5;
    static const quint8 list = 6;
    static const quint8 errorNaimIsUsed = 202;
    static const quint8 disconnectd = 203;
};

#endif // USER_H
