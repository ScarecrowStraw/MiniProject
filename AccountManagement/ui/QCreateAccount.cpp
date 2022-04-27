#include "QCreateAccount.h"
#include "ui_qcreateaccount.h"

#include <QDebug>
#include <QMessageBox>

QCreateAccount::QCreateAccount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QCreateAccount)
{
    m_model = new AMModel();

    ui->setupUi(this);

    connect(ui->createButton, &QPushButton::clicked, this, &QCreateAccount::createUser);

}

QCreateAccount::~QCreateAccount()
{
    delete ui;
}

void QCreateAccount::createUser()
{
    QString name = ui->nameInput->toPlainText();
    QString pass = ui->passInput->toPlainText();
    QString fullName = ui->fullNameInput->toPlainText();

    QUser u(name, pass, fullName);

    qDebug() << name << " " << pass << " " << fullName;

    bool result = m_model->addUser(u);

    if (result)
    {
        QMessageBox msgBox;
        msgBox.setText("Create user successed");
        msgBox.exec();

        this->close();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("User exited");
        msgBox.exec();
    }
}
