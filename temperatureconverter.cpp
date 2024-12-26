#include "temperatureconverter.h"
#include <cmath>
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

    ui->resultCelsius->setText("0.0");
    ui->resultFahrenteit->setText("0.0");

    connect(ui->exit, &QAction::triggered, this, &QCoreApplication::quit);

    //DoubleSpinBox
    ui->inputValue->setMinimum(0);
    ui->inputValue->setMaximum(999999);
    ui->inputValue->setDecimals(2);
    ui->inputValue->clear();

    connect(ui->inputValue, &QDoubleSpinBox::valueChanged, this, &MainWindow::on_inputValue_valueChanged);
}

MainWindow::~MainWindow(){ delete ui; }

double MainWindow::celsiusToFahrenheit(double input)
{
    return input * 1.8 + 32;
}

double MainWindow::fahrenheitToCelsius(double input)
{
    return (input - 32) / 1.8;
}

void MainWindow::on_inputValue_valueChanged(double inputValue){

    QString inputText = ui->inputValue->text();
    if (inputText.isEmpty()){
        ui->resultCelsius->clear();
        ui->resultFahrenteit->clear();
        return;
    }

    double resultCelsius = round(fahrenheitToCelsius(inputValue));    // Converte Fahrenheit para Celsius
    double resultFahrenheit = round(celsiusToFahrenheit(inputValue));  // Converte Celsius para Fahrenheit
    // Atualiza os rótulos com os resultados
    ui->resultCelsius->setNum(resultCelsius);
    ui->resultFahrenteit->setNum(resultFahrenheit);
}
