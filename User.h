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
  string pfp;
  string banner;
  size_t age;

public:
  Queue<Activity> activites;
  User(string name, string phone, string handel, int age,string pfp,string banner);

  User();
  void displayInfo();

  string getName() const;
  string getPhone() const;
  string getHandel() const;
  size_t getAge() const;
  string getPfp() const;
  string getBanner() const;

  void SetHandle(string newHandle) { this->handel = newHandle; }

  User(const User &other)
      : name(other.name), phone(other.phone), handel(other.handel),
        age(other.age),pfp(other.banner),banner(other.banner) {}
  User &operator=(const User &other) {
    if (this != &other) {
      // Copy each member variable
      name = other.name;
      phone = other.phone;
      handel = other.handel;
      age = other.age;
      pfp = other.pfp;
      banner = other.banner;
    }
    return *this;
  }

  void addPost(const string &content,const string &pic);

  void MakeCopy(User &user) {
    this->handel = user.handel;
    this->age = user.age;
    this->name = user.name;
    this->phone = user.phone;
    this->pfp = user.pfp;
    this->banner =user.banner;
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
