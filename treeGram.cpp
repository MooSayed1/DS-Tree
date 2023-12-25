#include "treeGram.h"


treeGram::treeGram(){

  }
treeGram::~treeGram(){

  }
void treeGram::test(){
  cout<<goFast.size();
}

bool treeGram::addUser(const string &name, const string &phone,
                       const string &handel, int age) {
  User temp(name, phone, handel, age);
  if (goFast.search(temp) == nullptr) {
    // goFast.insert(temp);
    return true;
  }
  return false;
}
bool treeGram::addPost(const string &handel, const string &content) {
  User *temp = goFast.search(handel);
  if (temp != nullptr) {
    temp->addPost(content);
    return true;
  }
  return false;
}
bool treeGram::addLikes(const string &handel, size_t post_num, size_t Likes) {
  User *temp = goFast.search(handel);
  if (temp != nullptr) {
    temp->addLikes(post_num, Likes);
    return true;
  }
  return false;
}
bool treeGram::addViews(const string &handel, size_t post_num, size_t Views) {
  User *temp = goFast.search(handel);
  if (temp != nullptr) {
    temp->addViews(post_num, Views);
    return true;
  }
  return false;
}
