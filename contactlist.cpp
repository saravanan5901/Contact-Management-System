#include "contactlist.h"

#include <iostream>

#include <bits/stdc++.h>

using namespace std;

extern string readContacts(); //from filehandler.cpp
extern void updateContacts(string); //from filehandler.cpp


ContactList::ContactList() //default constructor, loads contacts from the file
{
    string data = readContacts();
    if(!data.empty())
    {
        contacts = decode(data);
    }
}

vector<Contact*>& ContactList::getContacts()
{
    return contacts;
}

void ContactList::addContact(Contact* newcon) //pushes a contact object to the contactlist
{
    Contact* redun = findByName(newcon->getName());
    if(redun == nullptr)
        contacts.push_back(newcon);
    else //a contact with the specified name already exists
    {
        for(Number* n : newcon->getNumbers())
        {
            redun->getNumbers().push_back(n);
        }
        cout << "Updated existing contact" << endl;
    }
}

void ContactList::editContacts() //function that edits a contact
{
    if(contacts.empty())
    {
        cout << "The contact list is empty." << endl;
        return;
    }

    cout << "The existing values of a particular contact are displayed." << endl;
    cout << "To change a particular value, type a new value in place of the old one." << endl;
    cout  << "If a particular value is not to be changed, press Enter to move to the next value." << endl;

    string x;
    cout<<"Enter the contact name to be edited: " << endl;
    cin.ignore();
    getline(cin,x);

    vector<Contact *>::iterator it = contacts.begin();
    bool notfound=true;
    Contact* to_edit, *edited;

    for ( ; it!=contacts.end(); it++)
    {
        Contact* c = *it;
        if (x==(c->getName()))
        {
            contacts.erase(it);
            to_edit=c;
            notfound=false;
            break;
        }
    }
    if (notfound)
    {
        cout<< x<<" is not found"<<endl;
    }
    else
    {
        string x,num,fie;
        cout<<to_edit->getName()<<"\r";
        getline(cin,x);

        if(x.empty())
            x = to_edit->getName();
        edited=new Contact(x);

        Number* edit_Num;
        for (Number* n:to_edit->getNumbers())
        {
            //obtaining the new values from the user and updating the necessary changes
            cout<<n->getField()<<"\r";
            getline(cin,fie);

            if(fie.empty())
                fie = n->getField();

            cout<<n->getNum()<<"\r";
            getline(cin,num);
            if(num.empty())
                num = n->getNum();

            edit_Num=new Number(num,fie);
            edited->addNumber(edit_Num);
        }

        addContact(edited);
        cout<<"\n"<<x<<" has been edited"<<endl;
    }
}

void ContactList::deleteContacts() //function to delete a contact
{
    if(contacts.empty())
    {
        cout << "The contact list is empty." << endl;
        return;
    }

    string x;
    cout<<"\nEnter the name of the contact to be deleted: ";
    cin.ignore();
    getline(cin,x);

    vector<Contact*>::iterator it;
    it=contacts.begin();
    bool notfound=true;

    for ( ; it!=contacts.end(); it++)
    {
        Contact* c = *it;
        if (x==(c->getName())) //linear search for contact name
        {
            contacts.erase(it); //calling the erase function
            notfound=false;
            break;
        }
    }

    if (notfound)
    {
        cout<<"\n"<<x<<" is not found"<<endl;
    }
    else
    {
        cout<<"\n"<<x<<" has been deleted from your contacts"<<endl;
    }
}

void ContactList::display() //display all contacts in the contactlist
{
    if(contacts.empty())
    {
        cout << "The contact list is empty." << endl;
        return;
    }
    cout << "Displaying all contacts:\n" << endl;
    for(Contact* c: contacts)
    {
        cout << "Contact Name: " << c->getName() << endl;
        for(Number* n: c->getNumbers())
        {
            cout << n->getField() << ": ";
            cout << n->getNum() << endl;
        }
        cout << endl;
    }
}

void ContactList::addNewContacts() //add new contact(s) to the contactlist
{
    string cname, num, field;
    Contact* newcon;
    Number* newnum;
    int ch;
    bool stop = false;
    bool stop2 = false;
    do
    {
        cout << "Enter contact name: ";
        cin.ignore();
        getline(cin, cname);
        newcon = new Contact(cname);
        stop2 = false;
        while(!stop2)
        {
            cout << "Enter field name (press enter if the field is mobile): ";
            cin.ignore();
            getline(cin, field);
            //cout << "Value of field: " << field << endl;
            cout << "Enter number: ";
            cin >> num;
            if(field.empty())
                newnum = new Number(num);
            else
                newnum = new Number(num, field);
            newcon->addNumber(newnum);

            cout << "Enter 1 to continue adding another field, 2 to add another contact and 3 to stop adding contacts\n";
            cin >> ch;
            switch(ch)
            {
            case 2:
                stop2 = true;
                break;
            case 3:
                stop2 = stop = true;
                break;
            }
        }

        addContact(newcon);
    }
    while(!stop);

    cout << "Contacts added successfully" << endl;
}

vector<Contact*> ContactList::decode(string str) //function to decode a string and return a vector of contacts
{
    vector <Contact*> decoded;
    stringstream in(str);
    string contact, name, field, number;
    while(true)
    {
        getline(in, contact, ';');
        //cout << "Contact: " << contact << endl;

        if(contact == "")
            break;

        stringstream in2(contact);
        getline(in2, name, ':');

        std::replace(name.begin(), name.end(), '+', ' ');

       // cout << "Name: " << name << endl;

        decoded.push_back(new Contact(name));

        while(true)
        {
            getline(in2, field, '=');
            if(field == "")
                break;
             //cout << "Field: " << field<< endl;

            getline(in2, number, '&');
             //cout << "Number: " << number << endl;

            decoded.back()->addNumber(new Number(number, field));
        }
    }
    return decoded;
}

string ContactList::encodeAll() //encodes the vector of the current object and returns the encoded string
{
    string result = "";
    for(Contact* con: contacts)
    {
        result += con->encode();
    }
    return result;
}

void ContactList::updateInFile() //generates the encoded text and writes it to the file
{
    string res = encodeAll();
    updateContacts(res);
}

Contact* ContactList::findByName(std::string name) //returns a contact with the matching name
{
    for(Contact* c: contacts)
    {
        if(c->getName() == name)
        {
            return c;
        }
    }
    return nullptr;
}

Contact* ContactList::findByNumber(std::string number) //returns a contact with the matching number
{
    for(Contact* c: contacts)
    {
        vector <Number*> numbers = c->getNumbers();
        for(Number* n: numbers)
        {
            if(n->getNum() == number)
                return c;
        }
    }
    return nullptr;
}
