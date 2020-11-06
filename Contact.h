#ifndef CONTACT_H
#define CONTACT_H

#include <vector>
#include <algorithm>
#include "Number.h"

class Contact
{
    std::string name; //stores the name of the contact

    std::vector<Number*> numbers; //a vector of pointers to Number objects
public:
    Contact();
    Contact(std::string);

    std::string getName();
    std::vector<Number*>& getNumbers();
    void setName(std::string val);

    void addNumber(Number*);
    void display();

    std::string encode();
};

#endif // CONTACT_H
