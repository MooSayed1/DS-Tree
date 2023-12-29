#include "hashTable.h"
// #include "server.h"
#include "treeGram.h"
using namespace std;
int main() {
  treeGram t;
   t.addUser("Dr. Mahmmoud Mahdi", "00000", "Mahdi", 0,"https://images2.imgbox.com/3d/d8/zFvuqwEz_o.png","https://images2.imgbox.com/ba/2f/pMhSATMv_o.png");

   t.addPost("Mahdi", "{وَيَعْفُو عَن كَثِيرٍ}","https://i.pinimg.com/474x/98/5d/3c/985d3cb92dd7a7208afb8266956891e0.jpg");
   t.addPost("Mahdi", "اللهم ارحم عبداً يرجو رحمتك ويخشى عذابك","https://i.pinimg.com/474x/98/5d/3c/985d3cb92dd7a7208afb8266956891e0.jpg");
   t.addPost("Mahdi", "وَللدَّهرِ احلاءٌ وَامرارُ","https://i.pinimg.com/474x/98/5d/3c/985d3cb92dd7a7208afb8266956891e0.jpg");
   t.addPost("Mahdi", "ولسْـتُ أخـشى رجــوعَ الكفِّ خائِبةً \n إن كُنْتَ يا مالكَ المُلكِ الذي يُعْطِي","https://i.pinimg.com/474x/98/5d/3c/985d3cb92dd7a7208afb8266956891e0.jpg");

   t.addUser("Ahemd", "1", "GH", 5,"https://i.pinimg.com/474x/98/5d/3c/985d3cb92dd7a7208afb8266956891e0.jpg","https://i.pinimg.com/474x/98/5d/3c/985d3cb92dd7a7208afb8266956891e0.jpg");
   t.addPost("GH", "Hello","https://i.pinimg.com/474x/98/5d/3c/985d3cb92dd7a7208afb8266956891e0.jpg");
   t.addLikes("GH", 0, 10);
   t.addLikes("GH", 0, 10);
   t.addPost("GH", "Hello EZZ","https://i.pinimg.com/474x/98/5d/3c/985d3cb92dd7a7208afb8266956891e0.jpg");
   t.addPost("GH", "Hello2","https://i.pinimg.com/474x/98/5d/3c/985d3cb92dd7a7208afb8266956891e0.jpg");
   t.addPost("GH", "Hello3","https://i.pinimg.com/474x/98/5d/3c/985d3cb92dd7a7208afb8266956891e0.jpg");

   t.addLikes("GH", 2, 14);
   t.addLikes("GH", 2, 15);

   t.addUser("Ezz", "1", "EZZ", 5,"https://i.pinimg.com/474x/98/5d/3c/985d3cb92dd7a7208afb8266956891e0.jpg","https://i.pinimg.com/474x/98/5d/3c/985d3cb92dd7a7208afb8266956891e0.jpg");
   t.addPost("EZZ", "Hello","https://i.pinimg.com/474x/98/5d/3c/985d3cb92dd7a7208afb8266956891e0.jpg");
   t.addLikes("EZZ", 0, 10);
   t.addLikes("EZZ", 0, 10);
   t.addPost("EZZ", "Hello GH","https://i.pinimg.com/474x/98/5d/3c/985d3cb92dd7a7208afb8266956891e0.jpg");
   t.addPost("EZZ", "Hello2","https://i.pinimg.com/474x/98/5d/3c/985d3cb92dd7a7208afb8266956891e0.jpg");
   t.addPost("EZZ", "Hello3","https://i.pinimg.com/474x/98/5d/3c/985d3cb92dd7a7208afb8266956891e0.jpg");

   t.addLikes("EZZ", 2, 14);
   t.addLikes("EZZ", 2, 15);

   for(char i='A';i<'L';i++){

   t.addUser(string(1,i), "1", string(1,i), 5,"https://i.pinimg.com/474x/98/5d/3c/985d3cb92dd7a7208afb8266956891e0.jpg","https://i.pinimg.com/474x/98/5d/3c/985d3cb92dd7a7208afb8266956891e0.jpg");
   t.addPost(string(1,i), string(10,i),"https://i.pinimg.com/474x/98/5d/3c/985d3cb92dd7a7208afb8266956891e0.jpg");

   }

   t.test();
   t.Deploy();
   

  // MyServer::Deploy();
  return 0;
}
