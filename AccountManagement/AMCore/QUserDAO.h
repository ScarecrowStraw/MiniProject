#ifndef QUSERDAO_H
#define QUSERDAO_H

#include <QObject>

class QSqlDatabase;
class QUser;

class QUserDAO : public QObject
{
    Q_OBJECT
public:
    QUserDAO(QSqlDatabase& database);
    void init() const;

    void addUser(QUser& user) const;

    //TODO: Add CRUD function
    void updateUser(const QUser& user) const;
    void removeUser(int id) const;
    QVector<QUser*> users() const;

private:
    QSqlDatabase& m_database;
};

#endif // QUSERDAO_H
