
#ifndef AVLTREE_H
#define AVLTREE_H

#include "User.h"
// #include <ios>
#include <iostream>
#include <queue>

struct AVLNode {
  User data;
  AVLNode *left;
  AVLNode *right;
  int height;
  AVLNode(){
    left=NULL;
    right=NULL;
    height=0;
  };
};

class AVLTree {
  private:
  AVLNode *root ;

public:
  AVLTree(){
  root = NULL;
  };
  
  AVLNode *GetRoot();

  // Unit of help functions for insertion and deletion
  int GetHight(AVLNode *p) ;
  int getbalance(AVLNode *node) ;
  int max(int a, int b);

  // help functions on deletions
  AVLNode *InPre(AVLNode *p) ;
  AVLNode *InSucc(AVLNode *p) ;

  // For rotations
  AVLNode *LLRotation(AVLNode *p) ;
  
  AVLNode *LRRotation(AVLNode *p) ;
  

  AVLNode *RRRotation(AVLNode *p) ;
  
  AVLNode *RLRotation(AVLNode *p) ;
  

  // For Display
  void preOrder(AVLNode *root) ;
  
  void Levelorder(AVLNode *p) ;
  
  void Inorder(AVLNode *p) ;

  // Basic Operations

  AVLNode *insert(AVLNode *node, User key) ;
  
  AVLNode *remove(AVLNode *p, User key) ;

  AVLNode *search(AVLNode *root, User key) ;
  AVLNode *search(AVLNode *root, string key) ;

};

#endif // AVLTREE_H

