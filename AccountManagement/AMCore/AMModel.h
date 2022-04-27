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

    void login(QUser& user);
    void signOut();

    void addUser(QUser& user);

signals:

private:
    QDatabaseManager& m_dbManager;
    std::unique_ptr<QUser> m_currentUser;
};

#endif // AMMODEL_H
