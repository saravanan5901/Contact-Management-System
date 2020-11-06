#include "mytcpserver.h"
#include <string>
#include <iostream>

using namespace std;

MyTcpServer::MyTcpServer(string msg, QObject *parent) : QObject(parent), data(msg)
{
    server = new QTcpServer(this);

    const int port = 9999;

   connect(server, SIGNAL(newConnection()),this, SLOT(newConnection())); //connecting signal to slot

   //The following line starts up a TCP Server at port 9999
   if(!server->listen(QHostAddress::Any, port))
       cout << "Server could not start";
   else
       cout << "Server is up and running at port 9999. This server will remain active for one minute or until a receiver connects." << endl;
   server->waitForNewConnection(60000);
}

//The following function is called whenever a client connects to the server
void MyTcpServer::newConnection()
{
    cout << "Connected to receiver" << endl;
    QTcpSocket *socket = server->nextPendingConnection(); //getting the socket

    const char* msg = data.c_str();

    //Send the required data to the client
    socket->write(msg);

    socket->flush();
    socket->waitForBytesWritten(3000);
    socket->close();
    cout << "Data sent successfully" << endl;

}
