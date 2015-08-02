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
     * \brief on_connectDisConnect_clicked - подключить отключить клиент
     */
    void on_connectDisConnect_clicked();
    /*!
     * \brief onTextChanged - обработчик изменений текста
     */
    void onTextChanged();
    /*!
     * \brief on_plainTextEdit_cursorPositionChanged - обработчик изменения положения курсора
     */
    void on_plainTextEdit_cursorPositionChanged();
    /*!
     * \brief send - отправка блока сообщений
     */
    void send();
public slots:
    /*!
     * \brief keyPressEventT - обработчик нажатия на клавишу в редакторе
     * \param e
     */
    void keyPressEventT(QKeyEvent* e, int a);
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
     * \param com
     * \param in
     */
    void doComand(quint8 com, QDataStream &in);
};

#endif // NOTEPADWINDOW_H
