#ifndef TEMPERATURECONVERTER_H
#define TEMPERATURECONVERTER_H

#include <QMainWindow>
#include <QWidget>
#include <QDoubleSpinBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    // void update_spinBoxes_valueChanged(double arg1, double arg2, double arg3);

private:
    Ui::MainWindow *ui;

    void configureSpinBox(QDoubleSpinBox* spinBox);
    void configureInputSpinBoxes();
};
#endif
