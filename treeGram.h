#ifndef TREEGRAM_H
#define TREEGRAM_H

#include "AVLTree.h"
#include "LinkedList.h"
#include "User.h"
#include "hashTable.h"
#include "crow.h"
#include <vector>

class treeGram {
public:
  treeGram();
  ~treeGram();
  bool addUser(const string & name,const string & phone,const string & handel,int age,const string & pfpUrl,const string & bannerUrl);
  bool addPost(const string &handel,const string &content,const string & pic);
  bool addLikes(const string &handel,size_t post_num,size_t Likes);
  bool addViews(const string &handel,size_t post_num,size_t Views);
  void Deploy();
  void test();

private:
  HashTable goFast;
  vector<string>handels;
};

#endif //TREEGRAM_H
