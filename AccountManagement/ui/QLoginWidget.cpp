#include "QLoginWidget.h"
#include "ui_qloginwidget.h"

QLoginWidget::QLoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QLoginWidget)
{
    ui->setupUi(this);

    connect(ui->createButton, &QPushButton::clicked, this, [this] {
        emit createButtonClicked();
    });
}

QLoginWidget::~QLoginWidget()
{
    delete ui;
}
