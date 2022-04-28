#include "QHomeWidget.h"
#include "ui_qhomewidget.h"
#include "QUser.h"

QHomeWidget::QHomeWidget(QWidget *parent, AMModel* model) :
    QWidget(parent),
    ui(new Ui::QHomeWidget)
{
    ui->setupUi(this);
    m_model = model;
}

QHomeWidget::~QHomeWidget()
{
    delete ui;
}

void QHomeWidget::setTextHello()
{
   // ui->helloUser->setText("Hello " + m_model->m_currentUser->fullName());
}
