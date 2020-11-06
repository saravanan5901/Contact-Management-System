#include "Contact.h"
#include <iostream>
using namespace std;

Contact::Contact() //default constructor
{
    name = "";
}

Contact::Contact(string str) //parameterized constructor
{
    name = str;
}

//Accessor and mutator methods:

string Contact::getName()
{
    return name;
}

vector<Number*>& Contact::getNumbers()
{
    return numbers;
}

void Contact::setName(string name)
{
    this->name = name;
}

void Contact::addNumber(Number* n) //to add a new number
{
    numbers.push_back(n);
}

void Contact::display() //displaying the details of a contact
{
    cout << "Name: " << name << endl;
    cout << "Contact Details:\n";
    for(Number* n: numbers)
        n->display();
}

string Contact::encode()
{
    string result;
    result += name;
    result+= ":";
    for(Number* n:numbers)
    {
        result+=n->field;
        result+="=";
        result+=n->num;
        result+="&";
    }
    result+=";";

    std::replace(result.begin(), result.end(), ' ', '+');

    return result;
}
