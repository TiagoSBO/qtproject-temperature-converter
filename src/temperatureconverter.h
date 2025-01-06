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

    void onSpinBoxesValueChanged();

private:
    Ui::MainWindow *ui;

    void configureSpinBox(QDoubleSpinBox* spinBox, const QString& suffix);
    void configureInputSpinBoxes();
    void updateSpinBoxes(QDoubleSpinBox* source, QDoubleSpinBox* target, std::function<double(double)> conversionFunc);
};
#endif
