#include "unitconverter.h"
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
    configureValidators();


    // Connect the item to the comboBox
    connect(ui->chooseUnit, &QComboBox::currentIndexChanged, this, &MainWindow::on_chooseUnit_currentIndexChanged);
    // Connect the item2 to the comboBox2
    connect(ui->chooseUnit_2, &QComboBox::currentIndexChanged, this, &MainWindow::on_chooseUnit_2_currentIndexChanged);

}

MainWindow::~MainWindow(){ delete ui; }

//Config EditLIne to set Numbers;
void MainWindow::configureValidators(){
    QDoubleValidator* doublevalidator = new QDoubleValidator(0, 99999, 2, ui->setUnit);
    doublevalidator->setNotation(QDoubleValidator::StandardNotation);
    ui->setUnit->setValidator(doublevalidator);
}


QString MainWindow::on_chooseUnit_currentIndexChanged(int index){
    QString currentText = ui->chooseUnit->currentText();
    updateSecondComboBox(index, ui->chooseUnit_2->currentIndex());
    // qDebug() << "OUTRO: " << currentText;
    return  currentText;
}

QString MainWindow::on_chooseUnit_2_currentIndexChanged(int index){
    QString currentText2 = ui->chooseUnit_2->currentText();
    updateSecondComboBox(ui->chooseUnit->currentIndex(), index);
    // qDebug() << "OUTRO2: " << currentText2;
    return currentText2;
}

void MainWindow::updateSecondComboBox(int index1, int index2)
{
    // Obtém os textos selecionados em ambos os comboBoxes
    QString selectedText1 = ui->chooseUnit->itemText(index1);
    QString selectedText2 = ui->chooseUnit_2->itemText(index2);

    // Atualiza o primeiro comboBox: reativa todos os itens
    for (int i = 0; i < ui->chooseUnit_2->count(); ++i) {
        ui->chooseUnit_2->model()->setData(ui->chooseUnit_2->model()->index(i, 0), true, Qt::UserRole - 1);
    }

    // Atualiza o segundo comboBox: desativa o item correspondente ao selecionado no primeiro
    for (int i = 0; i < ui->chooseUnit_2->count(); ++i) {
        if (ui->chooseUnit_2->itemText(i) == selectedText1) {
            ui->chooseUnit_2->model()->setData(ui->chooseUnit_2->model()->index(i, 0), false, Qt::UserRole - 1);
        }
    }
}


