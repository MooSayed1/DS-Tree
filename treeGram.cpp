#include "treeGram.h"
#include <algorithm>
#include <cstdlib>
#include <random>
#include <chrono>       // std::chrono::system_clock

treeGram::treeGram() {}
treeGram::~treeGram() {}
void treeGram::test() {
  cout << goFast.size() << endl;
   
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng(seed);
    std::shuffle(std::begin(handels), std::end(handels), rng);

  for (unsigned int i = 0; i < handels.size(); i++) {
    cout << handels[i] << endl;
       goFast.search(handels[i])->displayInfo();
  }
}

bool treeGram::addUser(string name, string phone, string handel, int age) {

  if (goFast.search(handel) == NULL) {
    cout << "added User :" << handel << endl;
    handels.push_back(handel);
    goFast.insert(name, phone, handel, age);
    return true;
  }

  return false;
}
bool treeGram::addPost(const string &handel, const string &content) {
  User *temp = goFast.search(handel);

  if (temp != NULL) {
    cout << "added Post for User :" << handel << endl
         << "Content" << content << endl;

    temp->addPost(content);
    return true;
  }
  return false;
}
bool treeGram::addLikes(const string &handel, size_t post_num, size_t Likes) {

  User *temp = goFast.search(handel);
  if (temp != NULL) {
    cout << "added likes for User :" << handel << endl
         << "post : " << post_num << " by " << Likes << endl;

    temp->addLikes(post_num, Likes);
    return true;
  }
  return false;
}
bool treeGram::addViews(const string &handel, size_t post_num, size_t Views) {
  User *temp = goFast.search(handel);
  if (temp != NULL) {
    cout << "added views for User :" << handel << endl
         << "post : " << post_num << " by " << Views << endl;
    temp->addViews(post_num, Views);
    return true;
  }
  return false;
}
