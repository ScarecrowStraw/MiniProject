#include "QLoginWidget.h"
#include "ui_qloginwidget.h"
#include "QUser.h"

#include <QDebug>

QLoginWidget::QLoginWidget(QWidget *parent, AMModel *model) :
    QWidget(parent),
    ui(new Ui::QLoginWidget)
{
    ui->setupUi(this);

   m_model = model;

    connect(ui->createButton, &QPushButton::clicked, this, [this] {
        emit createButtonClicked();
    });
    connect(ui->loginButton, &QPushButton::clicked, this, &QLoginWidget::getLogindata);
}

QLoginWidget::~QLoginWidget()
{
    delete ui;
}

void QLoginWidget::getLogindata()
{
    QString usrname = ui->username->toPlainText();
    QString usrpass = ui->lineEdit->text();
    QUser usrlogin(usrname, usrpass);
//    usrlogin.setName(usrname);
//    usrlogin.setPass(usrpass);

    bool checker = m_model->login(usrlogin);

    if(checker){
        qDebug()<<"okela";
        emit loginSuccess();
        emit LoginUserInit();
    }
    else{
        emit loginFail();
    }
    qDebug()<< usrlogin.fullName();
}
