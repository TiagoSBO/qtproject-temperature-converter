#include "temperatureconverter.h"
#include "./ui_mainwindow.h"
#include "utilsfunctions.h"
#include <QRegularExpression>
#include <QDoubleSpinBox>
#include <QLineEdit>
#include <functional>
#include <QDebug>
#include <cmath>

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

    if (senderSpinBox == ui->spinBoxFahrenheit) {
        updateSpinBoxes(ui->spinBoxFahrenheit, ui->spinBoxCelsius, fahrenheitToCelsius);
        updateSpinBoxes(ui->spinBoxFahrenheit, ui->spinBoxKelvin, fahrenheitToKelvin);
    }else if (senderSpinBox == ui->spinBoxCelsius) {
        updateSpinBoxes(ui->spinBoxCelsius, ui->spinBoxFahrenheit, celsiusToFahrenheit);
        updateSpinBoxes(ui->spinBoxCelsius, ui->spinBoxKelvin, celsiusToKelvin);
    }else{
        updateSpinBoxes(ui->spinBoxKelvin, ui->spinBoxCelsius, kelvinToCelsius);
        updateSpinBoxes(ui->spinBoxKelvin, ui->spinBoxFahrenheit, kelvinToFahrenheit);
    }
}

void MainWindow::updateSpinBoxes(QDoubleSpinBox* source, QDoubleSpinBox* target, std::function<double(double)> conversionFunc) {
    target->blockSignals(true);

    double result = conversionFunc(source->value());

    //Rounds the result if the checkbox is checked.
    if (ui->checkBox->isChecked()){
        result = std::round(result * 100.0) / 100.0;
        source->setDecimals(2);
        target->setDecimals(2);
    }else {
        source->setDecimals(4);
        target->setDecimals(4);
    }

    target->setValue(result);
    target->blockSignals(false);
}

void MainWindow::configureSpinBox(QDoubleSpinBox* spinBox, const QString& suffix) {
    spinBox->setMinimum(-99999);
    spinBox->setMaximum(99999);
    spinBox->setDecimals(4);
    spinBox->setKeyboardTracking(false);
    spinBox->clear();

    QLineEdit* lineEdit = spinBox->findChild<QLineEdit*>();
    if (lineEdit) {
        lineEdit->setPlaceholderText("Enter value");

        QRegularExpression regExp("[-]?[0-9]*\\.?[0-9]{0,4}");
        QValidator* validator = new QRegularExpressionValidator(regExp, spinBox);
        lineEdit->setValidator(validator);
    }
    spinBox->setSuffix(suffix);
}

void MainWindow::configureInputSpinBoxes() {
    configureSpinBox(ui->spinBoxCelsius, " Cº");
    configureSpinBox(ui->spinBoxFahrenheit, " Fº");
    configureSpinBox(ui->spinBoxKelvin, " Kº");
}


