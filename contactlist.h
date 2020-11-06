#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include "Contact.h"

#include <vector>
#include <string>
#include <algorithm>


class ContactList
{
    std::vector <Contact*> contacts; //a vector of Contact objects

public:
    ContactList();

    std::vector<Contact*>& getContacts();

    void addNewContacts();
    void addContact(Contact*);
    void editContacts();
    void deleteContacts();

    std::string encodeAll();
    static std::vector<Contact*> decode(std::string);

    void display();
    void updateInFile();

    Contact* findByName(std::string);
    Contact* findByNumber(std::string);

};

#endif // CONTACTLIST_H
