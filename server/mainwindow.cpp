#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    s = new server(this);
    s->start(QHostAddress::LocalHost, 1234);
    connect(ui->connect, SIGNAL(clicked(bool)), this, SLOT(onСonnectСlicked()));
    connect(s, SIGNAL(log(QString)), this, SLOT(printLog(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printLog(QString s)
{
    ui->log->append(s);
}

void MainWindow::onConnectClicked()
{
    if (ui->connect->text() == "Остановить"){
        s->stop();
        ui->ip->setEnabled(true);
        ui->port->setEnabled(true);
        ui->connect->setText("Запустить");
    }
    else{
        if (s->start(QHostAddress(ui->ip->text()), ui->port->value())){
            ui->ip->setEnabled(false);
            ui->port->setEnabled(false);
            ui->connect->setText("Остановить");
        }
    }
}
