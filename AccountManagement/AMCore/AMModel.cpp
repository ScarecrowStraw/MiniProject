#include "AMModel.h"
#include "QUser.h"

#include <QDebug>

AMModel::AMModel(QObject *parent)
    : QObject{parent},
      m_dbManager(QDatabaseManager::instance()),
      m_currentUser(nullptr)
{
    qDebug() << "AMModel Init";
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
    bool result = m_dbManager.userDao.addUser(user);

    if(result){
        qDebug() << "Add successed";
    }
    else{
        qDebug() << "User exited";
    }
}
