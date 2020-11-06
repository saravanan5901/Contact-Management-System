#include "mytcpclient.h"
#include <iostream>
#include <fstream>
using namespace std;

MyTcpClient::MyTcpClient(string hostname, int port, ContactList& cl, QObject* parent):QObject(parent), cl(cl) //constructor
{
    socket = new QTcpSocket(this); //creates a new socket

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead())); //connects the signal to the slot
    connect(socket, SIGNAL(connected()), this, SLOT(connected())); //connects the signal to the slot

    //The following line uses the newly created socket to establish a connect to a server
    //The IP address / host name of the server and the port number are received as parameters
    socket->connectToHost(hostname.c_str(), port);
    cout << "Connecting to server..." << endl;

    //block the main thread until the client disconnects from the server
    socket->waitForDisconnected();
}

//The readyRead function is called when the client is ready to read incoming data from the server
void MyTcpClient::readyRead()
{
    char buf[1024] = {0}; //creating a sufficiently large character array

    //The following statement reads data from the server and places it into the character array
    socket->read(buf, sizeof(buf));

    string strbuf(buf);
    vector <Contact*> decoded = cl.decode(strbuf);
    for(Contact* c: decoded)
        cl.addContact(c);

    cl.updateInFile();

    cout << "Contacts received successfully!" << endl;
    socket->close();
}

void MyTcpClient::connected()
{
    cout << "Connected to server successfully" << endl;
}

