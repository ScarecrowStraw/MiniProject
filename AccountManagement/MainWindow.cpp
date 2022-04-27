#include "MainWindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    m_model = new AMModel();

    ui->setupUi(this);

    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::getLogindata);

}

MainWindow::~MainWindow()
{
}

void MainWindow::getLogindata()
{
    QString usrname = ui->username->toPlainText();
    QString usrpass = ui->lineEdit->text();
    QUser usrlogin;
    usrlogin.setName(usrname);
    usrlogin.setPass(usrpass);
    m_model->login(usrlogin);
    qDebug()<< usrlogin.name();
}


