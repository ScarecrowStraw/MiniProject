#include "MainWindow.h"
#include "QUser.h"
#include "QDatabaseManager.h"

#include <QApplication>
#include <QString>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QUser u("blalo", "123456", "SuperMan");

    w.m_model->addUser(u);

    w.show();

    return a.exec();
}
