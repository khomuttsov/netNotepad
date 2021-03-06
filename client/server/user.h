#ifndef USER_H
#define USER_H

#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QDebug>
#include <QMessageBox>

#include "server.h"

class server;
/*!
 * \brief The user class - класс клиента
 */
class user : public QObject
{
    Q_OBJECT
    friend class server;
public:
    /*!
     * \brief user - Конструктор создающий пользователя сервера с заданым дескриптором
     * \param desc - дескриптор
     * \param serv - сервер
     * \param parent - объект родитель
     */
    explicit user(int desc, server *serv, QObject *parent = 0);
    /*!
     * \brief isAuthentificatedUser - Прошел ли пользователь авторизацию
     * \return да\нет
     */
    inline bool isAuthentificatedUser() const { return isAuthentificated; }
    /*!
     * \brief getSocket - Получить сокет используемый пользователем
     * \return да\нет
     */
    inline QTcpSocket *getSocket() const { return socket; }
    /*!
     * \brief getName - Получить имя пользователя
     * \return имя
     */
    inline QString getName() const { return name; }
    /*!
     * \brief send - Прередать команду клиенту
     * \param c - команда
     */
    void send(qint8 c);
private:
    /*!
     * \brief socket - сокет для связи с клиентом
     */
    QTcpSocket *socket;
    /*!
     * \brief host - указатель на объект сервера
     */
    server *host;
    /*!
     * \brief name - Имя пользователя
     */
    QString name;
    /*!
     * \brief isAutched - Авторизовался ли пользователь
     */
    bool isAuthentificated;
    /*!
     * \brief sendUsers - Отправить список пользователей
     */
    void sendUsers();
private slots:
    /*!
     * \brief onConnect - Слот обрабатывающий подключение
     */
    void onConnect();
    /*!
     * \brief onDisconnect - Слот обрабатывающий отключение
     */
    void onDisconnect();
    /*!
     * \brief onReadyRead - Слот который считывает блок данных по готовности
     */
    void onReadyRead();
    /*!
     * \brief onError - Обработчик ошибок
     * \param e - ошибка
     */
    void onError(QAbstractSocket::SocketError e);


public:
    /*!
     * \brief authentificate - запрос авторизации
     */
    static const quint8 authentificate = 1;
    /*!
     * \brief editFile - Запрос на передачу изменений текста
     */
    static const quint8 editFile = 2;
    /*!
     * \brief usersList - Запрос на получение списка пользователей
     */
    static const quint8 usersList = 3;
    /*!
     * \brief list - Запрос на передачу списка изменений текста
     */
    static const quint8 list = 4;
    /*!
     * \brief errorNameIsUsed - Запрос на передачу сообщения о том что данное имя занято
     */
    static const quint8 errorNameIsUsed = 10;
    /*!
     * \brief disconnected - Запрос на разрыв соеденения
     */
    static const quint8 disconnected = 11;
};

#endif // USER_H
