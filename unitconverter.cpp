#include "unitconverter.h"
#include "./ui_mainwindow.h"
#include <QValidator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->exit, &QAction::triggered, this, &QCoreApplication::quit);

    {
        QDoubleValidator* doublevalidator = new QDoubleValidator(0, 99999, 2, ui->setUnit);
        doublevalidator->setNotation(QDoubleValidator::StandardNotation);
        ui->setUnit->setValidator(doublevalidator);
    }
}

MainWindow::~MainWindow(){ delete ui; }


