#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    s = new server(this, this);
    s->start(QHostAddress::LocalHost, 1234);
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
