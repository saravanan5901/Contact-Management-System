#ifndef NUMBER_H_INCLUDED
#define NUMBER_H_INCLUDED

#include <string>

class Number
{
    std::string num; //string to hold the actual number
    std::string field; //field to store the type of the number (mobile, landline, etc)
public:

    //Constructors:
    Number();
    Number(std::string, std::string = "Mobile");
    Number(int, std::string = "Mobile");
    void setNum(std::string);

    //Accessor and mutator methods:
    void setNum(int);
    std::string getNum();
    int getNumInt();
    void setField(std::string);
    std::string getField();

    void display();

    friend class Contact;
};

#endif // NUMBER_H_INCLUDED
