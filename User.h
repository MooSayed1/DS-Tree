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
  int age;
  Queue<Activity> activites;

public:
  User(string name, string phone,string handel, int age);

  User();
  void displayInfo() const;
  
  string getHandel() const;
   void SetHandle(string newHandle) {
      this->handel = newHandle;
  }



  void addPost(const string &content);
  


  void MakeCopy(User& user) {
      this->handel = user.handel;
      this->age = user.age;
      this->name = user.name;
      this->phone = user.phone;
  }
  void SetData() {
     
          cout << "Enter user name: ";
          cin>> this->name;

          cout << "Enter user phone: ";
          cin>>this->phone;

          cout << "Enter user handle: ";
          cin>> this->handel;

          cout << "Enter user age: ";
          cin>>this->age;
	}

  void addLikes(size_t post_num, size_t Likes);
  void addViews(size_t post_num, size_t Views);

};




#endif // USER_H
