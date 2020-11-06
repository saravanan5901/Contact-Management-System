#include <QCoreApplication>

#include <iostream>
#include <conio.h>

#include "mytcpserver.h"
#include "mytcpclient.h"

#include "contactlist.h"

using namespace std;

void cls()
{
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#endif
}

void enter()
{
    cout << "Press Enter to continue" << endl;
    getch();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ContactList cl;

    bool stoploop = false;
    string ip;
    int op;
    do
    {
        cls();
        cout << "Contact Management System" << endl << endl << endl;
        cout << "1. Add Contacts\n2. Edit Contact\n3. Display Contacts\n4. Delete Contacts\n5. Send Contacts\n6. Receive Contacts\n7. Exit\n" << endl;
        cout << "Enter your choice: ";
        cin >> op;
        cls();
        switch(op) //switch between various options. After add, edit or delete, the changes are written back to the file
        {
            case 1: cl.addNewContacts();
                cl.updateInFile();
                break;
            case 2: cl.editContacts();
                cl.updateInFile();
                break;
            case 3: cl.display();
                break;
            case 4: cl.deleteContacts();
                cl.updateInFile();
                break;
            case 5:
                if(cl.getContacts().empty())
                {
                    cout << "The contact list is empty." << endl;
                    break;
                }
                MyTcpServer(cl.encodeAll()); //start a TCP server
                break;
            case 6: cout << "Enter the IP Address of the sender" << endl;
                cin >> ip;
                MyTcpClient(ip, 9999, cl); //connect using TCP to the given IP address
                break;
            case 7: stoploop = true;
        }
        if(op!=7)
            enter();
    }while(!stoploop);

    return 0;
}
