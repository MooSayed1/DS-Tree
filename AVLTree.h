//
//#ifndef AVLTREE_H
//#define AVLTREE_H
//
//#include "User.h"
//// #include <ios>
//#include <iostream>
//#include <queue>
//
//struct AVLNode {
//  User data;
//  AVLNode *left;
//  AVLNode *right;
//  int height;
//  AVLNode(){
//    left=NULL;
//    right=NULL;
//    height=0;
//  };
//};
//
//class AVLTree {
//  private:
//  AVLNode *root ;
//
//public:
//  AVLTree(){
//  this->root = NULL;
//  };
//  
//  AVLNode *GetRoot();
//
//  // Unit of help functions for insertion and deletion
//  int GetHight(AVLNode *p) ;
//  int getbalance(AVLNode *node) ;
//  int max(int a, int b);
//
//  // help functions on deletions
//  AVLNode *InPre(AVLNode *p) ;
//  AVLNode *InSucc(AVLNode *p) ;
//
//  // For rotations
//  AVLNode *LLRotation(AVLNode *p) ;
//  AVLNode *LRRotation(AVLNode *p) ;
// 
//
//  AVLNode *RRRotation(AVLNode *p) ; 
//  AVLNode *RLRotation(AVLNode *p) ;
//  
//
//  // For Display
//  void preOrder(AVLNode *root) ;
//  
//  void Levelorder(AVLNode *p) ;
//  
//  void Inorder(AVLNode *p) ;
//
//  // Basic Operations
//
//  AVLNode *insert(AVLNode *node, User key) ;
//  
//  AVLNode *remove(AVLNode *p, string key) ;
//
//  AVLNode *search(AVLNode *root, User key) ;
//  AVLNode *search(AVLNode *root, string key) ;
//
//};
//
//#endif // AVLTREE_H

#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>
#include <string>
#include<queue>
#include"User.h"
using namespace std;

struct AVLNode {
    User key;
    AVLNode* left;
    AVLNode* right;
    int height;
    AVLNode() {
        left = NULL;
        right = NULL;
        height = 0;
    };
};
class AVLTree {
private:
    AVLNode* root;
public:
	// A utility function to get the 
	// height of the tree 
	AVLNode* root;
	AVLTree() {
		root = NULL;
	}

	AVLNode* GetRoot() {
		return root;
	}

	int height(AVLNode* N)
	{
		if (N == NULL)
			return 0;
		return N->height;
	}

	// A utility function to get maximum 
	// of two integers 
	int max(int a, int b)
	{
		return (a > b) ? a : b;
	}

	/* Helper function that allocates a
	new node with the given key and
	NULL left and right pointers. */
	AVLNode* newNode(User key)
	{
		AVLNode* node = new AVLNode();
		node->key.MakeCopy(key);
		node->left = NULL;
		node->right = NULL;
		node->height = 1; // new node is initially 
		// added at leaf 
		return(node);
	}

	// A utility function to right 
	// rotate subtree rooted with y 
	// See the diagram given above. 
	AVLNode* rightRotate(AVLNode* y)
	{
		AVLNode* x = y->left;
		AVLNode* T2 = x->right;

		// Perform rotation 
		x->right = y;
		y->left = T2;

		// Update heights 
		y->height = max(height(y->left),
			height(y->right)) + 1;
		x->height = max(height(x->left),
			height(x->right)) + 1;

		// Return new root 
		return x;
	}

	// A utility function to left 
	// rotate subtree rooted with x 
	// See the diagram given above. 
	AVLNode* leftRotate(AVLNode* x)
	{
		AVLNode* y = x->right;
		AVLNode* T2 = y->left;

		// Perform rotation 
		y->left = x;
		x->right = T2;

		// Update heights 
		x->height = max(height(x->left),
			height(x->right)) + 1;
		y->height = max(height(y->left),
			height(y->right)) + 1;

		// Return new root 
		return y;
	}

	// Get Balance factor of node N 
	int getBalance(AVLNode* N)
	{
		if (N == NULL)
			return 0;
		return height(N->left) - height(N->right);
	}

	// Recursive function to insert a key 
	// in the subtree rooted with node and 
	// returns the new root of the subtree. 
	void insertNode(User key) {
		this->root = insertNode(root, key);
	}

	AVLNode* insertNode(AVLNode* node, User NewUser)
	{
		/* 1. Perform the normal BST insertion */
		if (node == NULL)
			return(newNode(NewUser));

		if (NewUser.getHandel() < node->key.getHandel())
			node->left = insertNode(node->left, NewUser);
		else if (NewUser.getHandel() > node->key.getHandel())
			node->right = insertNode(node->right, NewUser);
		else // Equal keys are not allowed in BST 
			return node;

		/* 2. Update height of this ancestor node */
		node->height = 1 + max(height(node->left),
			height(node->right));

		/* 3. Get the balance factor of this ancestor
			node to check whether this node became
			unbalanced */
		int balance = getBalance(node);

		// If this node becomes unbalanced, then 
		// there are 4 cases 

		// Left Left Case 
		if (balance > 1 && NewUser.getHandel() < node->left->key.getHandel())
			return rightRotate(node);

		// Right Right Case 
		if (balance < -1 && NewUser.getHandel() > node->right->key.getHandel())
			return leftRotate(node);

		// Left Right Case 
		if (balance > 1 && NewUser.getHandel() > node->left->key.getHandel())
		{
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}

		// Right Left Case 
		if (balance < -1 && NewUser.getHandel() < node->right->key.getHandel())
		{
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}

		/* return the (unchanged) node pointer */
		return node;
	}

	// A utility function to print preorder 
	// traversal of the tree. 
	// The function also prints height 
	// of every node 
	void preOrder(AVLNode* root)
	{
		if (root != NULL)
		{
			cout << root->key.getHandel() << " ";
			preOrder(root->left);
			preOrder(root->right);
		}
	}
	void Levelorder(AVLNode* p) {
		queue<AVLNode*> q;
		cout << root->key.getHandel() << " ";
		q.push(p);
		while (!q.empty()) {
			p = q.front();
			q.pop();
			if (p->left) {
				cout << root->key.getHandel() << " ";
				q.push(p->left);
			}
			if (p->right) {
				cout << root->key.getHandel() << " ";
				q.push(p->right);
			}

		}
	}

	

	AVLNode* AVLTree::search(AVLNode* root, User key);
	AVLNode* AVLTree::search(AVLNode* root, string key);
};

#endif // AVLTREE_H
