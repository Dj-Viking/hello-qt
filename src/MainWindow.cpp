#include "MainWindow.h"
#include "Ui_MainWindow.h"

#include "QtCore/QMetaObject"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}