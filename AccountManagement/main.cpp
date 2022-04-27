#include "QUser.h"
#include "QDatabaseManager.h"
#include "AMModel.h"

#include <QApplication>
#include <QString>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AMModel* model;

    QUser u("king", "123456", "SuperMan");

    model->addUser(u);

    return a.exec();
}
