#ifndef QHOMEWIDGET_H
#define QHOMEWIDGET_H

#include <QWidget>

namespace Ui {
class QHomeWidget;
}

class QHomeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QHomeWidget(QWidget *parent = nullptr);
    ~QHomeWidget();

private:
    Ui::QHomeWidget *ui;
};

#endif // QHOMEWIDGET_H
