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
    connect(this, &MainWindow::something, this, &MainWindow::printSomething);
}

MainWindow::~MainWindow()
{
}

void MainWindow::getLogindata()
{
    QString name = ui->Name->toPlainText();
    qDebug() << name;

    emit something(name);
}

void MainWindow::printSomething(QString name)
{
    qDebug() << name;
}

