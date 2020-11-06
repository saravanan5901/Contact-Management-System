#include <iostream>
#include "convhandler.cpp"
#include "Number.h"

using namespace std;

Number::Number() //default constructor
{
    num = "";
    field = "";
}

//Other parameterized constructors:
Number::Number(string number, string field )
{
    num = number;
    this->field = field;
}

Number::Number(int number, string field )
{
    num = toString(number);
    this->field = field;
}

//Accessor and mutator methods:

void Number::setNum(string s)
{
    num = s;
}

void Number::setNum(int n)
{
    num = toString(n);
}

string Number::getNum()
{
    return num;
}

int Number::getNumInt()
{
    return toInt(num);
}

void Number::setField(string f)
{
    field = f;
}

string Number::getField()
{
    return field;
}

void Number::display() //display function
{
    cout << field << ": " << num << endl;
}
