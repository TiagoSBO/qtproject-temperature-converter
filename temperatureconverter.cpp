#include "temperatureconverter.h"
#include "./ui_mainwindow.h"
#include <QDoubleSpinBox>
// #include "utilsfunctions.h"
#include <QValidator>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->exit, &QAction::triggered, this, &QCoreApplication::quit);

    configureInputSpinBoxes();


    // connect(ui->spinBoxCelsius, &QDoubleSpinBox::valueChanged, this, &MainWindow::on_inputValue_valueChanged);
    // connect(ui->spinBoxFahrenheit, &QDoubleSpinBox::valueChanged, this, &MainWindow::on_inputValue_valueChanged);
    // connect(ui->spinBoxKelvin, &QDoubleSpinBox::valueChanged, this, &MainWindow::on_inputValue_valueChanged);

}

MainWindow::~MainWindow(){ delete ui; }

// void MainWindow::update_spinBoxes_valueChanged(double arg1, double arg2, double arg3)
// {

// }


void MainWindow::configureSpinBox(QDoubleSpinBox* spinBox) {
    spinBox->setMinimum(0);
    spinBox->setMaximum(999999);
    spinBox->setDecimals(2);
    spinBox->clear();
}

void MainWindow::configureInputSpinBoxes() {
    configureSpinBox(ui->spinBoxCelsius);
    configureSpinBox(ui->spinBoxFahrenheit);
    configureSpinBox(ui->spinBoxKelvin);
}


//     QString inputText = ui->inputValue->text();
//     if (inputText.isEmpty()){
//         ui->resultCelsius->clear();
//         ui->resultCelsius->clear();
//         return;
//     }

//     double resultCelsius = fahrenheitToCelsius(inputValue);    // Converte Fahrenheit para Celsius
//     double resultFahrenheit = celsiusToFahrenheit(inputValue);  // Converte Celsius para Fahrenheit

//     // Atualiza os rótulos com os resultados
//     ui->resultCelsius->setNum(resultCelsius);
//     ui->resultCelsius->setNum(resultFahrenheit);
//}


