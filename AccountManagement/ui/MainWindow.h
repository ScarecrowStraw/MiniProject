#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

#include "QCreateAccount.h"
#include "QLoginWidget.h"
#include "QHomeWidget.h"
#include "AMModel.h"
#include <QStackedWidget>

namespace Ui{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:

public slots:

public:
    Ui::MainWindow *ui;
    AMModel* m_model;
    QCreateAccount* m_createAccountWidget;
    QLoginWidget* m_loginWidget;
    QHomeWidget* m_homeWidget;
    QStackedWidget* m_stackedWidget;

};
#endif // MAINWINDOW_H
