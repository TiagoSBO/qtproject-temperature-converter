#include "temperatureconverter.h"
#include "./ui_mainwindow.h"
#include "utilsfunctions.h"
#include <QValidator>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //Exit Buttom
    ui->setupUi(this);

    connect(ui->exit, &QAction::triggered, this, &QCoreApplication::quit);

    resetResultLabels();
    configureInputSpinBox();

    connect(ui->inputValue, &QDoubleSpinBox::valueChanged, this, &MainWindow::on_inputValue_valueChanged);
}

MainWindow::~MainWindow(){ delete ui; }

void MainWindow::configureInputSpinBox(){
    ui->inputValue->setMinimum(0);
    ui->inputValue->setMaximum(999999);
    ui->inputValue->setDecimals(2);
    ui->inputValue->clear();
}

void MainWindow::resetResultLabels(){
    ui->resultCelsius->setText("0.0");
    ui->resultFahrenteit->setText("0.0");
}


void MainWindow::on_inputValue_valueChanged(double inputValue){

    QString inputText = ui->inputValue->text();
    if (inputText.isEmpty()){
        ui->resultCelsius->clear();
        ui->resultFahrenteit->clear();
        return;
    }
    double resultCelsius = fahrenheitToCelsius(inputValue);    // Converte Fahrenheit para Celsius
    double resultFahrenheit = celsiusToFahrenheit(inputValue);  // Converte Celsius para Fahrenheit

    // Atualiza os rótulos com os resultados
    ui->resultCelsius->setNum(resultCelsius);
    ui->resultFahrenteit->setNum(resultFahrenheit);
}
