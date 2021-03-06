#include "notepadwindow.h"
#include "ui_notepadwindow.h"

notepadWindow::notepadWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::notepadWindow)
{
    ui->setupUi(this);
    iRead = false;
    tChaing = false;
    haveError = false;
    sok = new QTcpSocket(this);
    pos = 0;
    t = new QTimer;
    connect(ui->connectDisConnect, SIGNAL(clicked(bool)), this, SLOT(onConnectDisConnectClicked()));
    connect(sok, SIGNAL(readyRead()), this, SLOT(onSokReadyRead()));
    connect(sok, SIGNAL(connected()), this, SLOT(onSokConnected()));
    connect(sok, SIGNAL(disconnected()), this, SLOT(onSokDisconnected()));
    connect(sok, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(onSokDisplayError(QAbstractSocket::SocketError)));
    connect(this, SIGNAL(readySend()), this, SLOT(send()));
    connect(ui->plainTextEdit, SIGNAL(keyPress(QKeyEvent*, int)), this, SLOT(keyPressEvent(QKeyEvent*, int)));
    connect(ui->plainTextEdit, SIGNAL(textChanged()), this, SLOT(onTextChanged()));
    connect(ui->plainTextEdit, SIGNAL(cursorPositionChanged()), this, SLOT(onPlainTextEditCursorPositionChanged()));
    connect(ui->save, SIGNAL(triggered(bool)), this, SLOT(saveB()));
    connect(t, SIGNAL(timeout()), this, SLOT(send()));
    ui->filesBox->hide();
}

notepadWindow::~notepadWindow()
{
    delete ui;
}

void notepadWindow::onSokConnected()
{

    ui->connectDisConnect->setText("Отключиться");
    ui->plainTextEdit->setEnabled(true);

    qDebug() << "Connected";

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint8)user::authentificate;
    out <<  ui->login->text();
    sok->write(block);
    t->start(500);
}

void notepadWindow::onSokDisconnected()
{
    ui->plainTextEdit->setEnabled(false);
    ui->ip->setEnabled(true);
    ui->port->setEnabled(true);
    ui->connectDisConnect->setText("Подключиться");
    if (!haveError && QMessageBox::Ok == QMessageBox::warning(this, "Соединение с сервером было потеряно", "Вы хотите сохранить документ в файл?", QMessageBox::Ok, QMessageBox::Cancel)){
        if (!save())
            QMessageBox::critical(this, "Что-то пошло не так!", "Не удалось сохранить файл");

    }
    ui->plainTextEdit->clear();
    haveError = false;
}

void notepadWindow::onSokReadyRead()
{
    QDataStream in(sok);
    //3 байт - команда серверу
    quint8 command;
    in >> command;

    if (command != user::list){
        doComand(command , in);
    }
    else{
        QList<QByteArray> comands;
        QByteArray b;
        in >> comands;
        while(!comands.isEmpty()){
            b = comands.takeAt(0);
            QDataStream in1(&b, QIODevice::ReadOnly);
            in1 >> command;
            doComand(command , in1);
        }
    }

}

void notepadWindow::onSokDisplayError(QAbstractSocket::SocketError socketError)
{
    qDebug() << socketError;
}

void notepadWindow::onConnectDisConnectClicked()
{
    if (ui->connectDisConnect->text() == "Подключиться"){
        sok->connectToHost(ui->ip->text(), ui->port->value());
    }
    else{
        ui->connectDisConnect->setText("Подключиться");
        sok->disconnectFromHost();
        ui->plainTextEdit->setEnabled(false);
    }
}

void notepadWindow::onTextChanged()
{
    tChaing = true;
    if (!iRead && current != ui->plainTextEdit->toPlainText()){
        QByteArray block;
        int localPos = lastPos;
        QDataStream out(&block, QIODevice::WriteOnly);
        editType et;
        QString text = ui->plainTextEdit->toPlainText();
        QString diff = getDiff(text , localPos, ui->plainTextEdit->textCursor().position(), arPos, et);
        out << user::editFile << (int)et << localPos << ui->plainTextEdit->textCursor().position() << arPos <<  diff;
        textEditList.append(block);
        current = ui->plainTextEdit->toPlainText();

    }
    tChaing = false;
}

void notepadWindow::onPlainTextEditCursorPositionChanged()
{

    lastPos = pos;
    pos = ui->plainTextEdit->textCursor().position();

}

void notepadWindow::send()
{
    if (textEditList.isEmpty()) return;
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << user::list << textEditList;
    textEditList.clear();
    sok->write(block);
}


void notepadWindow::keyPressEvent(QKeyEvent *e, int a)
{
    tChaing = true;
    arPos = a;
    if (e->key() == Qt::Key_Delete){

        QByteArray block;
        int localPos = pos;
        QDataStream out(&block, QIODevice::WriteOnly);
        editType et;
        QString text = ui->plainTextEdit->toPlainText();
        QString diff = getDiff(text , pos, pos, arPos, et);
        out << user::editFile << (int)et << localPos << localPos << a << diff;
        textEditList.append(block);
        current = updateText(ui->plainTextEdit->toPlainText(), et, localPos, localPos, arPos, diff);

    }
    tChaing = true;
}

void notepadWindow::saveB()
{
    if (!save())
        QMessageBox::critical(this, "Что-то пошло не так!", "Не удалось сохранить файл");
}

bool notepadWindow::save()
{
    QString ff = QFileDialog::getSaveFileName(this, "Выберете файл в который будет произведено сохранение","","*");
    if (ff.isEmpty())
        return false;
    QFile f(ff);
    if (!f.open(QIODevice::WriteOnly))
        return false;
    f.write(ui->plainTextEdit->toPlainText().toUtf8());
    f.close();
    return true;
}

void notepadWindow::doComand(quint8 com, QDataStream &in)
{
    switch (com) {
    case user::editFile:{
        QString diff;
        int type, start, end, anchor;
        in >> type >> start >> end >> anchor >> diff;
        iRead = true;
        //обрабатываем
        int lPos = pos;
        ui->plainTextEdit->setPlainText(updateText(ui->plainTextEdit->toPlainText(), (editType)type, start, end, anchor, diff));
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
        iRead = true;
        QString users, files;
        in >> users >> files;
        QStringList l;
        ui->users->clear();
        if (users != ""){
            l =  users.split(",");
            ui->users->addItems(l);
        }
        if (ui->plainTextEdit->toPlainText().isEmpty()){
            ui->plainTextEdit->setPlainText(files);
            current = files;
        }
        iRead = false;
    }
        break;
    case user::errorNameIsUsed:{
        haveError = true;
        ui->connectDisConnect->setText("Подключиться");
        QMessageBox::critical(this, "Ошибка соединения с сервером!", "Пользователь с таким именем уже существует.");
        sok->disconnectFromHost();
        ui->plainTextEdit->setEnabled(false);
    }
        break;
    case user::disconnected:{
        sok->disconnect();
    }
        break;
    default:
        break;
    }
}
