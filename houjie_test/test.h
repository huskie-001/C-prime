#pragma once
#include <iostream>
using namespace std;
class Person
{

private:
    string strName;
    string strAddress;
public:
    Person() = default;
    Person(const string &name,const string &add);
    Person(std::istream &is);
    string getName() const{return strName;}
    string getAddress() const{return strAddress;}

    istream &read(istream &is,Person &Per);
    ostream &print(ostream &os,const Person &Per);
};