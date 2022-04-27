#ifndef QCREATEACCOUNT_H
#define QCREATEACCOUNT_H

#include <QWidget>
#include "QUser.h"
#include "AMModel.h"

namespace Ui {
class QCreateAccount;
}

class QCreateAccount : public QWidget
{
    Q_OBJECT

public:
    explicit QCreateAccount(QWidget *parent = nullptr);
    ~QCreateAccount();

signals:
    void closed();

public slots:
    void createUser();

private:
    Ui::QCreateAccount *ui;
    AMModel* m_model;
};

#endif // QCREATEACCOUNT_H
