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
    void loginsignals(QUser userlogin);

public slots:
    void getLogindata();


public:
    AMModel *m_model;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
