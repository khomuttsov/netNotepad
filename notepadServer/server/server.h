#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>

#include "user.h"
#include "textcorefunc.h"

class user;
class server : public QTcpServer
{
    Q_OBJECT
public:
    friend class user;
    explicit server(QWidget *widget = 0, QObject *parent = 0);
    void textEdit(user* ho, QString file, editType type, int coursorStart, int coursorEnd, QString diff);
    bool isNameUsed(QString n) const;
    bool start(QHostAddress addr, qint16 port);

    QString getUsers( user* without = NULL ) const;
    QString getFiles() const;
protected:
    void incomingConnection(qintptr handle);
private:
    QList<user *> clients;
    QMap<QString, QString> files;
    QWidget *_widget;

private slots:
    void onRemoveUser(user* client);
signals:
    void log(QString t);
};

#endif // SERVER_H
