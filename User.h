#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
using namespace std;

class User {
private:
    string name;
    string phone;
		string handel;
    int age;
    int hashString(string str, int n); // This will Take 2 parameter str --> Handel Name and n --> Table Size 

public:
    User(const string& name, const string& phone,const string & handel, int age);
		User():name("UNKOWN"),phone("UNKOWN"),handel(""),age(0){}
    void displayInfo() const;
    int getHash(string str, int n);

};

#endif // USER_H
