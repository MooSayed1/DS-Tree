#include "User.h"
#include <functional>
#include <iostream>

User::User(const string &name, const string &phone, const string &handel,
           int age)
    : name(name), phone(phone), handel(handel), age(age) {}

void User::displayInfo() const {
  cout << "Name: " << name << "\nPhone: " << phone << "\nAge: " << age << endl;
}

int User::getHash(string str, int n) { return hashString(str, n); }

int hashString(string str, int n) {
  long long nn = n;
  long long sum = 0;
  for (int i = 0; i < (int)str.size(); ++i)
    sum = (sum * 26 + str[i] - 'a') % nn;
  return sum % nn;
}
