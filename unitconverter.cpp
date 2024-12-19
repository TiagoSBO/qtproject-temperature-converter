#include "unitconverter.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->exit, &QAction::triggered, this, &QCoreApplication::quit);
}

MainWindow::~MainWindow()
{
    delete ui;
}
