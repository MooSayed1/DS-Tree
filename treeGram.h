#include "AVLTree.h"
#include "LinkedList.h"
#include "User.h"
#include "hashTable.h"
#include "hash_map"

class treeGram {
public:
  treeGram();
  ~treeGram();
  bool addUser(const string &name, const string &phone, const string &handel,
               int age);
  bool addPost(const string &handel);


private:
  HashTable goFast;
};

