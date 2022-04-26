#include "QDatabaseManager.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlError>

void QDatabaseManager::debugQuery(const QSqlQuery& query)
{
    if (query.lastError().type() == QSqlError::ErrorType::NoError) {
        qDebug() << "Query OK:"  << query.lastQuery();
    } else {
       qWarning() << "Query KO:" << query.lastError().text();
       qWarning() << "Query text:" << query.lastQuery();
    }
}

QDatabaseManager& QDatabaseManager::instance()
{
    static QDatabaseManager instance;
    return instance;
}

QDatabaseManager::QDatabaseManager(const QString& path)
    : m_database(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"))),
      userDao(*m_database)
{
    m_database->setDatabaseName(path);
    m_database->open();

    userDao.init();
}

QDatabaseManager::~QDatabaseManager()
{
    m_database->close();
}


