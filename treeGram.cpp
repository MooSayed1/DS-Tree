#include "treeGram.h"

treeGram::treeGram() {}

treeGram::~treeGram() {}

bool treeGram::addUser(const string &name, const string &phone,
                       const string &handel, int age) {
  User temp(name,phone,handel,age);
  if (goFast.search(temp)==nullptr) {
    goFast.insert(temp);
  return true;
  }
  return false;
}
bool treeGram::addPost(const string &handel) {
  User *temp = goFast.search(handel);
  if (temp!=nullptr) {
    //TODO add activity properly and find a way to modify stats like views and like fast
  return true;
  }
  return false;
}
