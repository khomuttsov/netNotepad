#ifndef NOTEPADWINDOW_H
#define NOTEPADWINDOW_H

#include <QMainWindow>
#include "server/user.h"
#include "server/textcorefunc.h"
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
    void onSokConnected();
    void onSokDisconnected();
    void onSokReadyRead();
    void onSokDisplayError(QAbstractSocket::SocketError socketError);

    void on_connectDisConnect_clicked();

    void on_files_currentTextChanged(const QString &currentText);

    void on_plainTextEdit_textChanged();

    void on_files_currentRowChanged(int currentRow);

    void on_plainTextEdit_cursorPositionChanged();

private:
    Ui::notepadWindow *ui;
    QTcpSocket *sok;
    quint16 blockSize;
    int pos;
    bool iRead, tChaing;
};

#endif // NOTEPADWINDOW_H
