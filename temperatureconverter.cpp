#include "temperatureconverter.h"
#include "./ui_mainwindow.h"
#include <QValidator>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //Exit Buttom
    ui->setupUi(this);
    connect(ui->exit, &QAction::triggered, this, &QCoreApplication::quit);



    // // Connect the item to the comboBox
    // connect(ui->chooseUnit, &QComboBox::currentIndexChanged, this, &MainWindow::on_chooseUnit_currentIndexChanged);
    // // Connect the item2 to the comboBox2
    // connect(ui->chooseUnit_2, &QComboBox::currentIndexChanged, this, &MainWindow::on_chooseUnit_2_currentIndexChanged);

}

MainWindow::~MainWindow(){ delete ui; }

//Config EditLIne to set Numbers;
// void MainWindow::configureValidators(){
//     QDoubleValidator* doublevalidator = new QDoubleValidator(0, 99999, 2, ui->setUnit);
//     doublevalidator->setNotation(QDoubleValidator::StandardNotation);
//     ui->setUnit->setValidator(doublevalidator);
// }


