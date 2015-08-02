#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "server.h"

namespace Ui {

class MainWindow;
}
/*!
 * \brief The MainWindow class - класс главного окна сервера
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    /*!
     * \brief s - сервер
     */
    server *s;

private slots:
    /*!
     * \brief printLog - вывести лог
     * \param s - строка лога
     */
    void printLog(QString s);
    /*!
     * \brief on_connect_clicked - подключить отключить сервер
     */
    void on_connect_clicked();
};

#endif // MAINWINDOW_H
