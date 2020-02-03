#include "bme280Server.h"
#include <QJsonDocument>
#include <QJsonObject>

Bme280Server::Bme280Server(QWidget *parent) :
    QObject(parent)
{
    port = 2345;
    server = new QTcpServer(this);
    connect(server, &QTcpServer::newConnection,
            this, &Bme280Server::new_tcp_connection);
}

Bme280Server::~Bme280Server()
{
    delete server;
    delete socket;
}

void Bme280Server::setPort(const quint16 &port)
{
    this->port = port;
}

void Bme280Server::listen()
{
    if(!server->listen(QHostAddress::Any, port))
        qDebug() << "Server could not start";
    else
        qDebug() << "Server started!";
}

void Bme280Server::new_tcp_connection()
{
    // need to grab the socket
    socket = server->nextPendingConnection();
    socket->setReadBufferSize(512);
    connect(socket, &QTcpSocket::readyRead,
            this, &Bme280Server::read_data_from_socket);
}

void Bme280Server::read_data_from_socket()
{
    QByteArray data;
    QString str_data;

    if (socket->bytesAvailable())
    {
        data = socket->readAll();
        str_data = data.constData();
        QByteArray byte_data = str_data.toUtf8();
        QJsonObject json_data = QJsonDocument::fromJson(byte_data).object();
        emit getTemperature(json_data["temperature"].toDouble());

        socket->waitForBytesWritten(50);
        socket->close();    // closing the socket manually to avoid memory leaks
    }
    else
    {
        socket->write("Could not receive data");
        socket->flush();
        socket->waitForBytesWritten(50);
        socket->close();
    }
}
