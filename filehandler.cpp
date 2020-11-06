#ifndef FileHandler
#define FileHandler

#include <iostream>
#include <fstream>


using namespace std;

//This file handles all I/O from and to files

const string filename = "contacts.txt"; //Data is stored in a file called contacts.txt

string readContacts()
{
    cout << "Reading contacts from file." << endl;
    ifstream readStream(filename);
    if(!readStream.good())
    {
        cout << "Open failed!" << endl;
        return "";
    }
    string data;
    readStream >> data;
    return data;
}

void updateContacts(string encoded)
{
    ofstream outStream(filename, std::ios::trunc);

    outStream << encoded;
}
#endif
