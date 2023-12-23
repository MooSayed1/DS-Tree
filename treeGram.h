#include "AVLTree.h"
#include "LinkedList.h"
#include "User.h"
#include "hashTable.h"
#include "hash_map"
#include <cstddef>

class treeGram {
public:
  treeGram();
  ~treeGram();
  bool addUser(const string &name, const string &phone, const string &handel,
               int age);
  bool addPost(const string &handel,const string &content);
  bool addLikes(const string &handel,size_t post_num,size_t Likes);
  bool addViews(const string &handel,size_t post_num,size_t Views);

private:
  HashTable goFast;
};

