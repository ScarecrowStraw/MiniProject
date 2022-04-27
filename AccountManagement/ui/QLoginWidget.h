#ifndef QLOGINWIDGET_H
#define QLOGINWIDGET_H

#include <QWidget>
#include "AMModel.h"

namespace Ui {
class QLoginWidget;
}

class QLoginWidget : public QWidget
{
    Q_OBJECT

signals:
    void createButtonClicked();
    void loginSuccess();
    void loginFail();

public slots:
    void getLogindata();
public:
    explicit QLoginWidget(QWidget *parent = nullptr);
    ~QLoginWidget();

private:
    Ui::QLoginWidget *ui;
    AMModel* m_model;
};

#endif // QLOGINWIDGET_H
