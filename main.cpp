#include <iostream>
#include "treeGram.h"
#include "AVLTree.h"
#include "hashTable.h"
#include "User.h"

using namespace std;
int main()
{
    cout<<"Ahmed Mohsen"<<endl;
    treeGram obj;
    obj.addUser("test", "test","test", 0);
    obj.addUser("shit", "shit","shit", 0);
    obj.addUser("test", "test","test", 0);
    obj.addUser("test", "test","test", 0);
    obj.addUser("test", "test","test", 0);
    
    // AVLTree ob; 
    // obj.test();

    return 0;
}
