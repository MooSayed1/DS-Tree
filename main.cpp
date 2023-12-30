#include "hashTable.h"
#include "treeGram.h"
// #include "server.h"
using namespace std;
int main() {
  treeGram t;

  t.addUser("Dr.Mahmmoud ", "00000", "Mahdi", 0);

  t.addPost("Mahdi", "x ");
  t.addPost("Mahdi", "x ");

  t.addPost("Mahdi", "{وَيَعْفُو عَن كَثِيرٍ}");
  t.addPost("Mahdi", "اللهم ارحم عبداً يرجو رحمتك ويخشى عذابك");
  t.addPost("Mahdi", "وَللدَّهرِ احلاءٌ وَامرارُ");
  t.addPost("Mahdi",
            "ولسْـتُ أخـشى رجــوعَ الكفِّ خائِبةً \n إن كُنْتَ يا مالكَ المُلكِ الذي يُعْطِي");

  t.addLikes("Mahdi", 0, 85);
  t.addLikes("Mahdi", 1, 112);
  t.addLikes("Mahdi", 2, 106);
  t.addLikes("Mahdi", 3, 138);
  t.addLikes("Mahdi", 4, 104);
  t.addLikes("Mahdi", 5, 112);

  t.addUser("Mohamed ", "01092*****", "MooSayed", 20);
  t.addPost("MooSayed", "Chess");
  t.addPost("MooSayed", "وَصَبْرٌ جَمِيلٌ ۖ وَاللَّهُ الْمُسْتَعَانُ عَلَىٰ مَا تَصِفُونَ");
  t.addPost("MooSayed", "Gaza forever <3");
  t.addPost("MooSayed", "بنحبك دكتور مهدي ❤️");
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
  t.addPost("ENG abdo","الناس نوعين ناس بتصيح من المشاكل وناس بتحل المشاكل");

  t.addLikes("ENG abdo", 0, 30);

  t.addUser("The real one", "1", "The real one", 0);
  t.addPost("The real one", "slavery is coming, reconsider finding the truth");

  t.addUser("mohy", "1", "mohy", 0);
  t.addPost("mohy", "你为这一切做了什么");


  t.addUser("anas", "1", "ANAS", 0);
  t.addPost("ANAS", "سبحان الله والحمد لله ولا إله إلا الله والله أكبر");
  t.addPost("ANAS", "لا إله إلا أنت سبحانك إني كنت من الظالمين");

  t.addUser("Maro", "1", "TOMAKO", 1);
  t.addPost("TOMAKO", "Be better");

  t.addUser("Reaper", "1", "HIM", 0);
  t.addPost("HIM", "متحاولش تثير اعجاب الناس اللى حواليك مقابل اى جزء من نفسك اهتم بنفسك وحسن من نفسك والاعجاب هييجى بعدين");
  t.addPost("HIM", "الدين مش موضة مش حاجة بتظهر وتختفى مع الوقت ده الاساس لاى حاجة بتنفذها فى حياتك ");

  t.Deploy();

  // MyServer::Deploy();
  return 0;
}
