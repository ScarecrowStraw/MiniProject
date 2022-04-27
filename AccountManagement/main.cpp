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

    w.show();

    return a.exec();
}
