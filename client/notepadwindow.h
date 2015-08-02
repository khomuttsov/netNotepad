#ifndef NOTEPADWINDOW_H
#define NOTEPADWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include "server/user.h"
#include "server/textcorefunc.h"
#include <QTimer>
#include <windows.h>
namespace Ui {
class notepadWindow;
}

class notepadWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit notepadWindow(QWidget *parent = 0);
    ~notepadWindow();

private slots:
    /*!
     * \brief onSokConnected - Слот обрабатывающий подключение
     */
    void onSokConnected();
    /*!
     * \brief onSokDisconnected - Слот обрабатывающий отключение
     */
    void onSokDisconnected();
    /*!
     * \brief onSokReadyRead - Слот который считывает блок данных по готовности
     */
    void onSokReadyRead();
    /*!
     * \brief onSokDisplayError - Обработчик ошибок
     * \param e - ошибка
     */
    void onSokDisplayError(QAbstractSocket::SocketError socketError);
    /*!
     * \brief onConnectDisConnectClicked - подключить отключить клиент
     */
    void onConnectDisConnectClicked();
    /*!
     * \brief onTextChanged - обработчик изменений текста
     */
    void onTextChanged();
    /*!
     * \brief onPlainTextEditCursorPositionChanged - обработчик изменения положения курсора
     */
    void onPlainTextEditCursorPositionChanged();
    /*!
     * \brief send - отправка блока сообщений
     */
    void send();
public slots:
    /*!
     * \brief keyPressEvent - обработчик нажатия на клавишу в редакторе
     * \param e - клавиша
     * \param a - якорь который был установлен до нажатия клавиши
     */
    void keyPressEvent(QKeyEvent* e, int a);
    /*!
     * \brief saveB - кнопка сохранения
     */
    void saveB();
    /*!
     * \brief save - cj[hfytybt
     * \return  успешность
     */
    bool save();
private:
    Ui::notepadWindow *ui;
    /*!
     * \brief sok - Сокет
     */
    QTcpSocket *sok;
    /*!
     * \brief current - текущий текст
     */
    QString current;
    /*!
     * \brief pos, lastPos - позиции курсора
     */
    int pos, lastPos, arPos;
    /*!
     * \brief iRead, tChaing, iDoit, haveError - флаги
     */
    bool iRead, tChaing, iDoit, haveError;
    /*!
     * \brief textEditList - блок событий
     */
    QList<QByteArray> textEditList;
    /*!
     * \brief t - Таймер синхронизации
     */
    QTimer *t;
    /*!
     * \brief doComand - обработчик одного действия
     * \param com - команда которую нужно выполнить
     * \param in - поток входа аргументов
     */
    void doComand(quint8 com, QDataStream &in);
};

#endif // NOTEPADWINDOW_H
