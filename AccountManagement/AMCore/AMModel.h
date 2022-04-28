#ifndef AMMODEL_H
#define AMMODEL_H

#include <QObject>
#include <memory.h>

#include "QDatabaseManager.h"
#include "QUser.h"

class AMModel : public QObject
{
    Q_OBJECT
public:
    explicit AMModel(QObject *parent = nullptr);

    bool login(QUser& user);
    void signOut();

    bool addUser(QUser& user);

    QString getUserFullName();


signals:

private:
    QUser* m_currentUser;
    QDatabaseManager& m_dbManager;


};

#endif // AMMODEL_H
