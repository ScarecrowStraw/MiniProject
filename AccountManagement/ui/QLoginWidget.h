#ifndef QLOGINWIDGET_H
#define QLOGINWIDGET_H

#include <QWidget>

namespace Ui {
class QLoginWidget;
}

class QLoginWidget : public QWidget
{
    Q_OBJECT

signals:
    void createButtonClicked();

public:
    explicit QLoginWidget(QWidget *parent = nullptr);
    ~QLoginWidget();

private:
    Ui::QLoginWidget *ui;
};

#endif // QLOGINWIDGET_H
