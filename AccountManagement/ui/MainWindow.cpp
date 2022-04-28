#include "MainWindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      m_createAccountWidget(new QCreateAccount()),
      m_loginWidget(new QLoginWidget()),
      m_homeWidget(new QHomeWidget()),
      m_stackedWidget(new QStackedWidget())
{
    ui->setupUi(this);

    m_model = new AMModel();

    m_stackedWidget->addWidget(m_homeWidget);
    m_stackedWidget->addWidget(m_loginWidget);
    m_stackedWidget->addWidget(m_createAccountWidget);

    m_stackedWidget->setCurrentWidget(m_loginWidget);

    setCentralWidget(m_stackedWidget);

    connect(m_loginWidget, &QLoginWidget::createButtonClicked, this, [this] {
            m_stackedWidget->setCurrentWidget(m_createAccountWidget);
    });
    connect(m_loginWidget, &QLoginWidget::LoginUserInit, m_homeWidget, &QHomeWidget::setTextHello);
    connect(m_loginWidget, &QLoginWidget::loginSuccess, this, [this] {
            m_stackedWidget->setCurrentWidget(m_homeWidget);
    });
    connect(m_loginWidget, &QLoginWidget::loginFail, this, [this] {
            m_stackedWidget->setCurrentWidget(m_homeWidget);
    });

    connect(m_createAccountWidget, &QCreateAccount::closeWidget, this, [this] {
            qDebug() << "Something here";
            m_stackedWidget->setCurrentWidget(m_loginWidget);
    });
}

MainWindow::~MainWindow()
{
}


