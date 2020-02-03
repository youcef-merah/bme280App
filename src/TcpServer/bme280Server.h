#ifndef BME380SERVER_H
#define BME380SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QWidget>
#include <QObject>

#include "bme280Server_global.h"

using namespace std;

class BME280SERVER_EXPORT Bme280Server : public QObject
{
    Q_OBJECT

public:
    explicit Bme280Server(QWidget *parent = nullptr);
    ~Bme280Server();

    void setPort(const quint16 &value);
    void listen(void);

private:
    quint16 port;
    QTcpServer *server;
    QTcpSocket *socket;

private slots: // related to the TCP server
void new_tcp_connection();
void read_data_from_socket();

signals:
    void getTemperature(double);
};

#endif // BME380SERVER_H
