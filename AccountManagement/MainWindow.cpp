#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_model = new AMModel();
}

MainWindow::~MainWindow()
{
}

