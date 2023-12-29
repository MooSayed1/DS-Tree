#include "hashTable.h"
#include "treeGram.h"
// #include "server.h"
using namespace std;
int main() {
  treeGram t;

  t.addUser("Dr. Mahmmoud Mahdi", "00000", "Mahdi", 0);

   t.addPost("Mahdi", "{وَيَعْفُو عَن كَثِيرٍ}");
   t.addPost("Mahdi", "اللهم ارحم عبداً يرجو رحمتك ويخشى عذابك");
   t.addPost("Mahdi", "وَللدَّهرِ احلاءٌ وَامرارُ");
   t.addPost("Mahdi", "ولسْـتُ أخـشى رجــوعَ الكفِّ خائِبةً \n إن كُنْتَ يا مالكَ المُلكِ الذي يُعْطِي");

  t.addUser("Mohamed Elsayed", "01092*****", "MooSayed", 20);
   t.addPost("MooSayed", "وَصَبْرٌ جَمِيلٌ ۖ وَاللَّهُ الْمُسْتَعَانُ عَلَىٰ مَا تَصِفُونَ");
   t.addPost("MooSayed", "Gaza forever <3");
   t.addPost("MooSayed", "testing");
   t.addPost("MooSayed", "وَصَبْرٌ جَمِيلٌ ۖ وَاللَّهُ الْمُسْتَعَانُ عَلَىٰ مَا تَصِفُونَ");
   

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

   t.addUser(string(3,i), "1", string(1,i), 5);
   t.addPost(string(1,i), string(10,i));

   }

   for (int i=0;i<10;i++){

   t.addPost("A", string(10,i+'0'));
   }
   t.test();
   t.Deploy();
   

  // MyServer::Deploy();
  return 0;
}
