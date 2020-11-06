#ifndef MYTCPCLIENT_H
#define MYTCPCLIENT_H
#include <QTcpSocket>
#include <QObject>

#include "contactlist.h"

class MyTcpClient: public QObject
{
    Q_OBJECT
public:
    explicit MyTcpClient(std::string, int, ContactList&, QObject *parent = 0); //constructor

signals:

public slots:
    void readyRead();
    void connected();

public:
    QTcpSocket* socket; //a pointer to a QTcpSocket
private:
    ContactList& cl; //the contactlist involved in the connection
};

#endif // MYTCPCLIENT_H
