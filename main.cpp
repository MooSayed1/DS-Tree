#include <iostream>
#include <ostream>
#include "treeGram.h"
#include "AVLTree.h"
#include "User.h"


// #include "hashTable.h"
// #include "hashTable.h"
using namespace std;
int main()
{
    treeGram obj;
    obj.addUser("test", "test","test", 0);
    cout<<endl;
    obj.addUser("shit", "shit","shit", 0);
    obj.addUser("test", "test","test", 0);
    obj.addUser("test", "test","test", 0);
    obj.addUser("test", "test","test", 0);
    
    // obj.test();
    cout<<"Ahmed Mohsen"<<endl;
        // obj.test();

    return 0;
}
