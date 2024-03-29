#include "MainWindow.h"
#include "Ui_MainWindow.h"

#include "QtCore/QMetaObject"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete m_ui;
}