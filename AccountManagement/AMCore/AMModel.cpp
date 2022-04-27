#include "AMModel.h"
#include "QUser.h"

AMModel::AMModel(QObject *parent)
    : QObject{parent},
      m_dbManager(QDatabaseManager::instance()),
      m_currentUser(nullptr)
{
    QUser u("Test", "123456", "SuperMan");
    m_dbManager.userDao.addUser(u);
}

void AMModel::login(const QUser &user)
{
    // TODO: Check user in database
    m_currentUser->setName(user.name());
    m_currentUser->setPass(user.pass());
    m_currentUser->setFullName(user.fullName());
}

void AMModel::signOut()
{
    m_currentUser = nullptr;
}

void AMModel::addUser(QUser &user)
{
    m_dbManager.userDao.addUser(user);
}
