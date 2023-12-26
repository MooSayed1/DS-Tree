#include "AVLTree.h"
#include "User.h"
#include "hashTable.h"
#include "treeGram.h"

using namespace std;
int main() {
  AVLTree t;
  User u1("1", "1", "c", 5);
  User u2("1", "1", "r", 5);
  User u3("1", "1", "a", 5);
  User u4("1", "1", "x", 5);
  User u5("1", "1", "z", 5);

  t.insert(u1);
  t.insert(u2);
  t.insert(u3);
  t.insert(u4);
  t.insert(u5);
  
  t.printPreorder();

  return 0;
}
