#include "treeGram.h"
#include "AVLTree.h"
#include "hashTable.h"
#include "User.h"

using namespace std;
int main()
{
    AVLTree t;
    User u1("1","1","c",5);
    User u2("1","1","r",5);
    User u3("1","1","a",5);
    User u4("1","1","x",5);
    User u5("1","1","z",5);
   
    t.TempinsertInAvLTree(u1);
    t.TempinsertInAvLTree(u2);
    t.TempinsertInAvLTree(u3);
    t.TempinsertInAvLTree(u4);
    t.TempinsertInAvLTree(u5);

    t.search(t.GetRoot(), "a")->key.displayInfo();

        
    



    //return 0;
}
