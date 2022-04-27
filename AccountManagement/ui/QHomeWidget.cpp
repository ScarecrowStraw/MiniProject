#include "QHomeWidget.h"
#include "ui_qhomewidget.h"

QHomeWidget::QHomeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QHomeWidget)
{
    ui->setupUi(this);
}

QHomeWidget::~QHomeWidget()
{
    delete ui;
}
