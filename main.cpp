#include "treeGram.h"
#include "AVLTree.h"
#include "hashTable.h"
#include "User.h"

using namespace std;
int main()
{
    AVLTree t;
    User u1("1","1","c",5);
    User u2("1","1","b",5);
    User u3("1","1","a",5);
    
    t.insertNode(t.GetRoot(), u1);
    t.insertNode(t.GetRoot(), u2);
    t.insertNode(t.GetRoot(), u3);
    
    t.Levelorder(t.GetRoot());
    
    
    




    return 0;
}
