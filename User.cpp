#include "User.h"
#include <iostream>
#include <string>

void User::displayInfo() const {
  cout << "Name: " << name << "\nPhone: " << phone << "\nAge: " << age << endl;
}

string User::getHandel() const { return this->handel; }

User::User() : name("UNKOWN"), phone("UNKOWN"), handel(""), age(0) {}

User::User(const string &name, const string &phone, const string &handel,
           int age)
    : name(name), phone(phone), handel(handel), age(age) {}
void User::addPost(const string &content) {
  this->activites.enqueue(Activity(content));
}
void User::addLikes(size_t post_num, size_t Likes) {

  this->activites[post_num].addLikes(Likes);
}
void User::addViews(size_t post_num, size_t Views) {
  this->activites[post_num].addViews(Views);
}
