#ifndef USER_H
#define USER_H

#include "Activity.h"
#include "Queue.h"
#include <cstddef>
#include <iostream>
#include <string>
using namespace std;

class User {
private:
  string name;
  string phone;
  string handel;
  size_t age;
  Queue<Activity> activites;

public:
  User(string name, string phone, string handel, int age);

  User();
  void displayInfo();

  string getName() const;
  string getPhone() const;
  string getHandel() const;
  size_t getAge() const;

  void SetHandle(string newHandle) { this->handel = newHandle; }

  User(const User &other)
      : name(other.name), phone(other.phone), handel(other.handel),
        age(other.age) {}
  User &operator=(const User &other) {
    if (this != &other) {
      // Copy each member variable
      name = other.name;
      phone = other.phone;
      handel = other.handel;
      age = other.age;
    }
    return *this;
  }

  void addPost(const string &content);

  void MakeCopy(User &user) {
    this->handel = user.handel;
    this->age = user.age;
    this->name = user.name;
    this->phone = user.phone;
  }
  void SetData() {

    cout << "Enter user name: ";
    cin >> this->name;

    cout << "Enter user phone: ";
    cin >> this->phone;

    cout << "Enter user handle: ";
    cin >> this->handel;

    cout << "Enter user age: ";
    cin >> this->age;
  }

  void addLikes(size_t post_num, size_t Likes);
  void addViews(size_t post_num, size_t Views);
};

#endif // USER_H
