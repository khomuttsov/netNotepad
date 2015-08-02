#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QFile>

#include "user.h"
#include "textcorefunc.h"

class user;
/*!
 * \brief The server class - класс сервера
 */
class server : public QTcpServer
{
    Q_OBJECT
public:
    friend class user;
    explicit server(QObject *parent = 0);
    /*!
     * \brief textEdit - обработать еденичное изменение текста
     * \param who - от кого
     * \param type - тип изменений
     * \param coursorStart - начало
     * \param coursorEnd -конец
     * \param coursorEnd - курсор в начале выделения
     * \param diff -разница
     */
    void textEdit(user* who, editType type, int coursorStart, int coursorEnd, int anchor, QString diff);
    /*!
     * \brief textEdit - обработать блок изменений текста
     * \param who - от какого пользователя
     * \param comands - блок
     */
    void textEdit(user *who, QList<QByteArray> comands);
    /*!
     * \brief isNameUsed - проверяет является ли имя занятым
     * \param n -имя
     * \return да\нет
     */
    bool isNameUsed(QString n) const;
    /*!
     * \brief start - запустить сервер
     * \param addr - адрес сервера
     * \param port - порт сервера
     * \return успешность запуска
     */
    bool start(QHostAddress addr, qint16 port);
    /*!
     * \brief stop - остановить сервер
     */
    void stop();
    /*!
     * \brief getUsers - Получить список пользователей через запятую
     * \param without - указатель на пользователя которого следует исключить из списка
     * \return список
     */
    QString getUsers( user* without = NULL ) const;
protected:
    /*!
     * \brief incomingConnection - создаем нового клиента
     * \param handle - хендел клиента
     */
    void incomingConnection(qintptr handle);
private:
    /*!
     * \brief clients - список клиентов
     */
    QList<user *> clients;
    /*!
     * \brief file - редактируемый файл
     */
    QString file;
    /*!
     * \brief f - файл в котором хранятся данные сервера
     */
    QFile *f;
private slots:
    /*!
     * \brief onRemoveUser - удаляет пользователя
     * \param client - указатель на пользователя
     */
    void onRemoveUser(user* client);
signals:
    /*!
     * \brief log - Сигнал для передачи строки лога во вне
     * \param t - строка
     */
    void log(QString t);
};

#endif // SERVER_H
