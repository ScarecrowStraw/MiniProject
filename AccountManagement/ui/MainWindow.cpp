#include "MainWindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      m_createAccountWidget(new QCreateAccount()),
      m_loginWidget(new QLoginWidget()),
      m_homeWidget(new QHomeWidget())
{
    ui->setupUi(this);

    setCentralWidget(m_loginWidget);

    connect(m_loginWidget, &QLoginWidget::createButtonClicked, this, [this] {
            setCentralWidget(m_createAccountWidget);
    });

    connect(m_createAccountWidget, &QWidget::destroyed, this, [this] {
            setCentralWidget(m_loginWidget);
    });
}

MainWindow::~MainWindow()
{
}


