#include "QUserDAO.h"
#include "QDatabaseManager.h"
#include "QUser.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlError>

QUserDAO::QUserDAO(QSqlDatabase& database)
    : m_database(database)
{

}

void QUserDAO::init() const
{
    if(!m_database.tables().contains("users"))
    {
        QSqlQuery query(m_database);
        query.exec("CREATE TABLE users (id INTEGER PRIMARY KEY AUTOINCREMENT, name text NOT NULL, pass text NOT NULL, fullName text NOT NULL)");

        if (query.lastError().type() == QSqlError::ErrorType::NoError) {
            qDebug() << "Query OK:"  << query.lastQuery();
        } else {
            qWarning() << "Query KO:" << query.lastError().text();
            qWarning() << "Query text:" << query.lastQuery();
        }
    }
}

void QUserDAO::addUser(QUser &user) const
{
    // TODO: Check exited user
    QSqlQuery query(m_database);
    query.prepare("INSERT INTO users (name, pass, fullName) VALUES (:name, :pass, :fullName)");

    qDebug() << user.name();
    qDebug() << user.pass();
    qDebug() << user.fullName();

    query.bindValue(":name", user.name());
    query.bindValue(":pass", user.pass());
    query.bindValue(":fullName", user.fullName());

    query.exec();
    user.setId(query.lastInsertId().toInt());
}
