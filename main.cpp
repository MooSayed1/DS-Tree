#include "hashTable.h"
#include "treeGram.h"
// #include "server.h"
using namespace std;
int main() {
  treeGram t;
   t.addUser("Ahemd", "1", "GH", 5);
   t.addPost("GH", "Hello");
   t.addLikes("GH", 0, 10);
   t.addLikes("GH", 0, 10);
   t.addPost("GH", "Hello EZZ");
   t.addPost("GH", "Hello2");
   t.addPost("GH", "Hello3");

   t.addLikes("GH", 2, 14);
   t.addLikes("GH", 2, 15);

   t.addUser("Ezz", "1", "EZZ", 5);
   t.addPost("EZZ", "Hello");
   t.addLikes("EZZ", 0, 10);
   t.addLikes("EZZ", 0, 10);
   t.addPost("EZZ", "Hello GH");
   t.addPost("EZZ", "Hello2");
   t.addPost("EZZ", "Hello3");

   t.addLikes("EZZ", 2, 14);
   t.addLikes("EZZ", 2, 15);

   for(char i='A';i<'L';i++){

   t.addUser(string(1,i), "1", string(1,i), 5);
   t.addPost(string(1,i), string(10,i));

   }

   t.test();
   t.Deploy();
   

  // MyServer::Deploy();
  return 0;
}
