#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(std::string, QObject *parent = 0); //constructor

signals:

public slots:
    void newConnection();

private:
    QTcpServer* server; //pointer to QTcpServer

    std::string data; //holds the data to be sent to the client (encoded string)
};

#endif // MYTCPSERVER_H
