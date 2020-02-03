#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->therm->setMaxTemperature(50);
    ui->therm->setMinTemperature(0);

    server = new Bme280Server(this);

    connect(server, &Bme280Server::getTemperature,
            this, &MainWindow::setTemperature);

    server->setPort(2345);
    server->listen();
}

MainWindow::~MainWindow()
{
    delete server;
    delete ui;
}

void MainWindow::setTemperature(double temp)
{
    ui->therm->setCurrentTemperature(temp);
}
