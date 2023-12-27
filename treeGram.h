#ifndef TREEGRAM_H
#define TREEGRAM_H

#include "AVLTree.h"
#include "LinkedList.h"
#include "User.h"
#include "hashTable.h"
#include <vector>

class treeGram {
public:
  treeGram();
  ~treeGram();
  bool addUser(string name,string phone,string handel,int age);
  bool addPost(const string &handel,const string &content);
  bool addLikes(const string &handel,size_t post_num,size_t Likes);
  bool addViews(const string &handel,size_t post_num,size_t Views);
  void test();

private:
  HashTable goFast;
  vector<string>handels;
};

#endif //TREEGRAM_H
