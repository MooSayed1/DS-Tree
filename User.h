#ifndef USER_H
#define USER_H

#include "Activity.h"
#include "Queue.h"
#include <cstddef>
#include <iostream>
#include <string>
using std::cout;
using std::string;

class User {
private:
  string name;
  string phone;
  string handel;
  int age;
  Queue<Activity> activites;

public:
  User(string name, string phone,string handel, int age);

  User();
  void displayInfo() const;
  string getHandel() const;

  void addPost(const string &content);

  void addLikes(size_t post_num, size_t Likes);
  void addViews(size_t post_num, size_t Views);
};

#endif // USER_H
