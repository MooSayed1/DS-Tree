#include "treeGram.h"


treeGram::treeGram(){

  }
treeGram::~treeGram(){

  }
void treeGram::test(){
  cout<<goFast.size();
}

bool treeGram::addUser(string name,string phone,string handel,int age) {

  if (goFast.search(handel) == NULL) {
    // goFast.search(handel)->displayInfo();
    // cout<<goFast.search(handel);
    goFast.insert(name, phone, handel, age);
    return true;
  }

  return false;
}
bool treeGram::addPost(const string &handel, const string &content) {
  User *temp = goFast.search(handel);
  if (temp != NULL) {
    temp->addPost(content);
    return true;
  }
  return false;
}
bool treeGram::addLikes(const string &handel, size_t post_num, size_t Likes) {
  User *temp = goFast.search(handel);
  if (temp != NULL) {
    temp->addLikes(post_num, Likes);
    return true;
  }
  return false;
}
bool treeGram::addViews(const string &handel, size_t post_num, size_t Views) {
  User *temp = goFast.search(handel);
  if (temp != NULL) {
    temp->addViews(post_num, Views);
    return true;
  }
  return false;
}
