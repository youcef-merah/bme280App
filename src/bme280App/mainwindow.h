#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bme280Server.h"
#include "thermometer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void setTemperature(double);

private:
    Ui::MainWindow *ui;
    Bme280Server *server;
    QMap<QString, double> data;
};
#endif // MAINWINDOW_H
