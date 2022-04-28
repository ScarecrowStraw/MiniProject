#ifndef QHOMEWIDGET_H
#define QHOMEWIDGET_H

#include <QWidget>
#include "AMModel.h"

namespace Ui {
class QHomeWidget;
}

class QHomeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QHomeWidget(QWidget *parent = nullptr, AMModel *model = nullptr);
    ~QHomeWidget();
public slots:
    void setTextHello();
private:
    Ui::QHomeWidget *ui;
    AMModel* m_model;
};

#endif // QHOMEWIDGET_H
