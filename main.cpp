#include "hashTable.h"
#include "treeGram.h"

using namespace std;
int main() {
  treeGram t;
   t.addUser("1", "1", "aaa", 5);
   t.addPost("aaa", "Hello");
   t.addLikes("aaa", 0, 10);
   t.addLikes("aaa", 0, 10);
   t.addPost("aaa", "Hello1");
   t.addPost("aaa", "Hello2");
   t.addPost("aaa", "Hello3");
  
   t.addLikes("aaa", 2, 14);
   t.addLikes("aaa", 2, 15);
   t.test();

  return 0;
}
