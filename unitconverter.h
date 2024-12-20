#ifndef UNITCONVERTER_H
#define UNITCONVERTER_H

#include <QMainWindow>

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

    QString on_chooseUnit_currentIndexChanged(int index);
    QString on_chooseUnit_2_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    void CelsiusToFahrenheit();
    void fahrenheitToCelsius();
    void configureValidators();
    void updateSecondComboBox(int index, int index2);

};
#endif
