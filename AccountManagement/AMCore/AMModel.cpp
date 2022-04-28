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

bool AMModel::login( QUser &user)
{
    bool checkdone = m_dbManager.userDao.isloginUserExits(user);

    m_currentUser = new QUser(user.name(), user.pass());

    if(checkdone){
        m_currentUser->setFullName(user.fullName());

        qDebug()<< m_currentUser->fullName();

        return true;
    }
    else {
        qDebug()<<"fail";
        return false;
    }
}

void AMModel::signOut()
{
    m_currentUser = nullptr;
}

bool AMModel::addUser(QUser &user)
{
    bool result = m_dbManager.userDao.addUser(user);

    if(result){
        qDebug() << "Add successed";
        return true;
    }
    else{
        qDebug() << "User exited";
        return false;
    }
}

QString AMModel::getUserFullName()
{
    return m_currentUser->fullName();
}
