#include "MainWindow.h"
#include "QUser.h"
#include "QDatabaseManager.h"
#include "QUserDAO.h"

#include <QApplication>
#include <QString>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QSqlDatabase* db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));

    db->setDatabaseName(DATABASE_FILENAME);
    db->open();

    QUserDAO dao(*db);

    dao.init();

    QUser u("lacie", "123456", "SuperMan");


    dao.addUser(u);

    return a.exec();
}
