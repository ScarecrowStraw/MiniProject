#include "QUser.h"

QUser::QUser(QObject *parent)
    : QObject{parent}
{

}

QUser::QUser(QString name, QString pass, QString fullName)
    : m_name(name),
      m_pass(pass),
      m_fullName(fullName)
{
}

QUser::~QUser()
{

}

QString QUser::name() const
{
    return m_name;
}

QString QUser::pass() const
{
    return m_pass;
}

QString QUser::fullName() const
{
    return m_fullName;
}

int QUser::id() const
{
    return m_id;
}

void QUser::setId(const int &id)
{
    m_id = id;
}

void QUser::setName(const QString &name)
{
    m_name = name;
}

void QUser::setPass(const QString &pass)
{
    m_pass = pass;
}

void QUser::setFullName(const QString &fullName)
{
    m_fullName = fullName;
}
