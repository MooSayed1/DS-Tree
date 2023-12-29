#include "hashTable.h"
#include "treeGram.h"
// #include "server.h"
using namespace std;
int main() {
  treeGram t;

  t.addUser("Dr.Mahmmoud ", "00000", "Mahdi", 0);

  t.addPost("Mahdi", " ");
  t.addPost("Mahdi", " ");

  t.addPost("Mahdi", "{وَيَعْفُو عَن كَثِيرٍ}");
  t.addPost("Mahdi", "اللهم ارحم عبداً يرجو رحمتك ويخشى عذابك");
  t.addPost("Mahdi", "وَللدَّهرِ احلاءٌ وَامرارُ");
  t.addPost("Mahdi",
            "ولسْـتُ أخـشى رجــوعَ الكفِّ خائِبةً \n إن كُنْتَ يا مالكَ المُلكِ الذي يُعْطِي");

  t.addUser("Mohamed ", "01092*****", "MooSayed", 20);
  t.addPost("MooSayed", "Chess");
  t.addPost("MooSayed", "وَصَبْرٌ جَمِيلٌ ۖ وَاللَّهُ الْمُسْتَعَانُ عَلَىٰ مَا تَصِفُونَ");
  t.addPost("MooSayed", "Gaza forever <3");
  t.addPost("MooSayed", "testing");

  t.addUser("Anon Miraj", "s","EZZ", 0);
  t.addPost("EZZ", "hello world");
  t.addPost("EZZ", "مرحبا عالم");
  t.addPost("EZZ", "ازيك يا احمد حسام 😏");
  t.addPost("EZZ", "Linux Supremacy");
  t.addPost("EZZ", "{قُلْ بِفَضْلِ اللَّهِ وَبِرَحْمَتِهِ فَبِذَلِكَ فَلْيَفْرَحُوا هُوَ خَيْرٌ مِمَّا يَجْمَعُونَ}");

  t.addUser("Ahemd Elghrabawy", "s","GH", 0);
  t.addPost("GH", "تحيا السيتي ");
  t.addPost("GH", "بنحبك دكتور مهدي ❤️");
  t.addPost("GH", "{ بَلۡ أَحۡیَاۤءٌ عِندَ رَبِّهِمۡ یُرۡزَقُونَ }");

  t.addUser("Sayed Ahmed", "x","onlychads", 0);
  t.addPost("onlychads", "cat");
  t.addPost("onlychads", "CAT");
  t.addPost("onlychads", "Me message to ahmed hossam is 남자들은 불가피하게 소멸에 빠질 것이다.");

  t.addUser("alaa turing", "x","ahmed hossam", 0);
  t.addPost("ahmed hossam", "Be nice 😔, but why");

  t.addUser("ENG abdo"," ","ENG abdo", 0);
  t.addPost("Eng abdo","الناس نوعين ناس بتصيح من المشاكل وناس بتحل المشاكل");

  t.addUser("The real one", "1", "The real one", 0);
  t.addPost("The real one", "slavery is coming, reconsider finding the truth");

  t.addUser("mohy", "1", "mohy", 0);
  t.addPost("mohy", "你为这一切做了什么");


  t.addUser("Test", "1", "TEST", 0);

  t.addPost("Test", "1");

  t.Deploy();

  // MyServer::Deploy();
  return 0;
}
