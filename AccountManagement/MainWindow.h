#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include "AMModel.h"

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
    void something(QString name);

public slots:
    void getLogindata();
    void printSomething(QString name);


public:
    AMModel *m_model;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
