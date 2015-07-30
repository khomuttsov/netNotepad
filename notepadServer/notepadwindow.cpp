#include "notepadwindow.h"
#include "ui_notepadwindow.h"

notepadWindow::notepadWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::notepadWindow)
{
    ui->setupUi(this);
    iRead = false;
    tChaing = false;
    sok = new QTcpSocket(this);
    pos = 0;
    connect(sok, SIGNAL(readyRead()), this, SLOT(onSokReadyRead()));
    connect(sok, SIGNAL(connected()), this, SLOT(onSokConnected()));
    connect(sok, SIGNAL(disconnected()), this, SLOT(onSokDisconnected()));
    connect(sok, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(onSokDisplayError(QAbstractSocket::SocketError)));
    connect(this, SIGNAL(readySend()), this, SLOT(send()));
    connect(ui->plainTextEdit, SIGNAL(keyPress(QKeyEvent*)), this, SLOT(keyPressEventT(QKeyEvent*)));
    ui->filesBox->hide();
}

notepadWindow::~notepadWindow()
{
    delete ui;
}

void notepadWindow::onSokConnected()
{
    blockSize = 0;
    qDebug() << "Connected";

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;
    out << (quint8)user::autch;
    out <<  ui->login->text();
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    sok->write(block);
}

void notepadWindow::onSokDisconnected()
{

}

void notepadWindow::onSokReadyRead()
{
    QDataStream in(sok);
    //если считываем новый блок первые 2 байта это его размер
    if (blockSize == 0) {
        //если пришло меньше 2 байт ждем пока будет 2 байта
        if (sok->bytesAvailable() < (int)sizeof(quint16))
            return;
        //считываем размер (2 байта)
        in >> blockSize;
        qDebug() << "_blockSize now " << blockSize;
    }
    //ждем пока блок прийдет полностью
    if (sok->bytesAvailable() < blockSize)
        return;
    else
        //можно принимать новый блок
        blockSize = 0;
    //3 байт - команда серверу
    quint8 command;
    in >> command;
    qDebug() << "Received command " << command;

    switch (command) {
    case user::editFile:{
        QString diff;
        int type, start, end;
        in >> type >> start >> end >> diff;
        iRead = true;
        //обрабатываем
        int lPos = pos;
        qDebug() << appdateText(ui->plainTextEdit->toPlainText(), (editType)type, start, end, diff);
        ui->plainTextEdit->setPlainText(appdateText(ui->plainTextEdit->toPlainText(), (editType)type, start, end, diff));
        QTextCursor tc= ui->plainTextEdit->textCursor();
        if (start <= lPos){
            lPos += end - start;
        }
        tc.setPosition(lPos);
        ui->plainTextEdit->setTextCursor(tc);

        iRead = false;
    }
        break;
    case user::usersList:{
        QString users, files;
        in >> users >> files;
        QStringList l;
        ui->users->clear();
        if (users != ""){
            l =  users.split(",");
            ui->users->addItems(l);
        }
        ui->files->clear();
        if (files != ""){
            l =  files.split(",");
            ui->files->addItems(l);
        }
    }
        break;
    case user::filesList:{
        QString files;
        in >> files;
        if (files == "")
            return;
        QStringList l =  files.split(",");
        ui->files->addItems(l);
    }
    case user::errorNaimIsUsed:{
        ui->connectDisConnect->setText("Подключиться");
        QMessageBox::critical(this, "Ошибка соединения с сервером!", "Пользователь с таким именем уже существует.");
        sok->disconnectFromHost();
        ui->plainTextEdit->setEnabled(false);
    }
        break;
    default:
        break;
    }
}

void notepadWindow::onSokDisplayError(QAbstractSocket::SocketError socketError)
{

}

void notepadWindow::on_connectDisConnect_clicked()
{
    if (ui->connectDisConnect->text() == "Подключиться"){
        ui->connectDisConnect->setText("Отключиться");
        sok->connectToHost(ui->ip->text(), ui->port->value());
        ui->plainTextEdit->setEnabled(true);
    }
    else{
        ui->connectDisConnect->setText("Подключиться");
        sok->disconnectFromHost();
        ui->plainTextEdit->setEnabled(false);
    }
}

void notepadWindow::on_files_currentTextChanged(const QString &currentText)
{

}

void notepadWindow::on_plainTextEdit_textChanged()
{

}

void notepadWindow::on_files_currentRowChanged(int currentRow)
{
    blockSize = 0;
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;
    out << (quint8)user::chaingCurFile;
    out <<  ui->files->currentItem()->text();
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    sok->write(block);
    ui->plainTextEdit->setEnabled(true);
}

void notepadWindow::on_plainTextEdit_cursorPositionChanged()
{
    tChaing = true;
    if (!iRead && current != ui->plainTextEdit->toPlainText()){
        QByteArray block;
        int localPos = pos;
        QDataStream out(&block, QIODevice::WriteOnly);
        editType et;
        QString text = ui->plainTextEdit->toPlainText();
        QString diff = getDiff(text , pos,ui->plainTextEdit->textCursor().position(), et);
        out << (quint16)0 << user::editFile << (int)et << localPos << ui->plainTextEdit->textCursor().position() << diff;
        out.device()->seek(0);
        out << (quint16)(block.size() - sizeof(quint16));
        sok->write(block);
        current = ui->plainTextEdit->toPlainText();
    }
    pos = ui->plainTextEdit->textCursor().position();
    tChaing = false;
}


void notepadWindow::keyPressEventT(QKeyEvent *e)
{
    tChaing = true;
    if (e->key() == Qt::Key_Delete){
        QByteArray block;
        int localPos = pos;
        QDataStream out(&block, QIODevice::WriteOnly);
        editType et;
        QString text = ui->plainTextEdit->toPlainText();
        QString diff = getDiff(text , pos, pos, et);
        out << (quint16)0 << user::editFile << (int)et << localPos << localPos << diff;
        out.device()->seek(0);
        out << (quint16)(block.size() - sizeof(quint16));
        sok->write(block);
        current = appdateText(ui->plainTextEdit->toPlainText(), et, localPos, localPos, diff);

    }
    tChaing = true;
}
