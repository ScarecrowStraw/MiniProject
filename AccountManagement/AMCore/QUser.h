#ifndef QUSER_H
#define QUSER_H

#include <QObject>
#include <QString>

//TODO: Encode password before add to database

class QUser : public QObject
{
    Q_OBJECT

public:
    QUser(QObject *parent = nullptr);
    QUser(QString name, QString pass, QString fullName);

    ~QUser();

    QString name() const;
    QString pass() const;
    QString fullName() const;
    int id() const;

    void setId(const int& id);
    void setName(const QString& name);
    void setPass(const QString& pass);
    void setFullName(const QString& fullName);

signals:

private:
    int m_id;
    QString m_name;
    QString m_pass;
    QString m_fullName;
};

#endif // QUSER_H
