#include "User.h"
#include <iostream>

User::User(const string &name, const string &phone, const string &handel,
           int age)
    : name(name), phone(phone), handel(handel), age(age) {}

void User::displayInfo() const {
  cout << "Name: " << name << "\nPhone: " << phone << "\nAge: " << age << endl;
}

string User::getHandel()const { return this->handel; }

