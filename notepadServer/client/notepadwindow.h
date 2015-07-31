#ifndef NOTEPADWINDOW_H
#define NOTEPADWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
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
public slots:

    void keyPressEventT(QKeyEvent* e);
    void saveB();
    bool save();
private:
    Ui::notepadWindow *ui;
    QTcpSocket *sok;
    quint16 blockSize;
    QString current;
    int pos, lastPos;
    bool iRead, tChaing, iDoit;
};

#endif // NOTEPADWINDOW_H
