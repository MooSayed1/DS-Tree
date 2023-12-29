#include "hashTable.h"
// #include "server.h"
#include "treeGram.h"
using namespace std;
int main() {
  treeGram t;
   t.addUser("Dr. Mahmmoud Mahdi", "00000", "Mahdi", 0,"https://scontent.fcai20-5.fna.fbcdn.net/v/t39.30808-6/351316316_816877079445330_1791305687539301796_n.jpg?ccb=1-7&_nc_sid=efb6e6&_nc_ohc=KvIf9yOVmqwAX9-oQpR&_nc_ht=scontent.fcai20-5.fna&oh=00_AfBuH6vQurBQkFdo4_OOf_ZOgtPhY1Xcu7QjAT9HZUPJSw&oe=65923275","https://scontent.fcai20-5.fna.fbcdn.net/v/t39.30808-6/398137693_305537618934294_1318043544634511248_n.jpg?ccb=1-7&_nc_sid=783fdb&_nc_ohc=3jIU9aiM8bQAX8DARhN&_nc_ht=scontent.fcai20-5.fna&oh=00_AfCNki33EGuzLMrtUdDBmh9d8uro5S0MhARIWoMfhM_NrA&oe=6593E123");

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
