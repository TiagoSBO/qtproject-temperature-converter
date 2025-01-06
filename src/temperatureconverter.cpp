#include "temperatureconverter.h"
#include "./ui_mainwindow.h"
#include "utilsfunctions.h"
#include <QDoubleSpinBox>
#include <QLineEdit>
#include <functional>
#include <QDebug>

using ConvertFunction = std::function<double(double)>;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->exit, &QAction::triggered, this, &QCoreApplication::quit);

    configureInputSpinBoxes();

    connect(ui->spinBoxCelsius, &QDoubleSpinBox::valueChanged, this, &MainWindow::onSpinBoxesValueChanged);
    connect(ui->spinBoxFahrenheit, &QDoubleSpinBox::valueChanged, this, &MainWindow::onSpinBoxesValueChanged);
    connect(ui->spinBoxKelvin, &QDoubleSpinBox::valueChanged, this, &MainWindow::onSpinBoxesValueChanged);

}

MainWindow::~MainWindow(){ delete ui; }

void MainWindow::onSpinBoxesValueChanged(){

    QObject* senderSpinBox = sender();
    QString a = "safasfs";

    if (senderSpinBox == ui->spinBoxFahrenheit) {
        updateSpinBoxes(ui->spinBoxFahrenheit, ui->spinBoxCelsius, fahrenheitToCelsius);
        updateSpinBoxes(ui->spinBoxFahrenheit, ui->spinBoxKelvin, fahrenheitToKelvin);
    }else if (senderSpinBox == ui->spinBoxCelsius) {
        updateSpinBoxes(ui->spinBoxCelsius, ui->spinBoxFahrenheit, celsiusToFahrenheit);
        updateSpinBoxes(ui->spinBoxCelsius, ui->spinBoxKelvin, celsiusToKelvin);
    }

}

void MainWindow::updateSpinBoxes(QDoubleSpinBox* source, QDoubleSpinBox* target, std::function<double(double)> conversionFunc) {
    double result = conversionFunc(source->value());
    target->setValue(result);
}

void MainWindow::configureSpinBox(QDoubleSpinBox* spinBox, const QString& suffix) {
    spinBox->setMinimum(-99999);
    spinBox->setMaximum(99999);
    spinBox->setDecimals(2);
    spinBox->clear();

    QLineEdit* lineEdit = spinBox->findChild<QLineEdit*>();
    if (lineEdit) {
        lineEdit->setPlaceholderText("Enter value");
    }
    spinBox->setSuffix(suffix);
}

void MainWindow::configureInputSpinBoxes() {
    configureSpinBox(ui->spinBoxCelsius, " Cº");
    configureSpinBox(ui->spinBoxFahrenheit, " Fº");
    configureSpinBox(ui->spinBoxKelvin, " Kº");
}



