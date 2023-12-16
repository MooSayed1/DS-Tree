#include<iostream>
#include <queue>
struct AVLNode
{
	int data;
	AVLNode* left;
	AVLNode* right;
	int height;
};
AVLNode* root = NULL;

class AVLTree {
public:
	int GetHight(AVLNode* p) {
		int hl, hr;
		hl = (p && p->left) ? p->left->height : 0;
		hr = (p && p->right) ? p->right->height : 0;

		return hl > hr ? hl + 1 : hr + 1;

		// Note we get the hight by calc the backwards hights make the max and + 1 to the new level
	}
	int getbalance(AVLNode* node) {
		int hl, hr;
		hl = node && node->left ? node->left->height : 0;
		hr = node && node->right ? node->right->height : 0;

		return hl - hr;

	}


	int max(int a, int b)
	{
		return (a > b) ? a : b;
	}


	AVLNode* LLRotation(AVLNode* p) {
		// p is a node that is impalance
		AVLNode* left_p = p->left; // this node will be the parent "root" 
		AVLNode* right_left_p = p->left->right; // will be the left of p"root"

		p->left = right_left_p;
		left_p->right = p;

		// then modify the hights
		// right_left_p its hight not changed
		p->height = GetHight(p);
		left_p->height = GetHight(left_p);

		if (root == p)
			root = left_p;

		return left_p; // new root
	}

	void preOrder(AVLNode* root)
	{
		if (root != NULL)
		{
			std::cout << root->data << " ";
			preOrder(root->left);
			preOrder(root->right);
		}
	}
	void Levelorder(AVLNode* p) {
		std::queue<AVLNode*> q;
		std::cout << p->data << " ";
		q.push(p);
		while (!q.empty()) {
			p = q.front();
			q.pop();
			if (p->left) {
				std::cout << p->left->data << " ";
				q.push(p->left);
			}
			if (p->right) {
				std::cout << p->right->data << " ";
				q.push(p->right);
			}

		}
	}

	AVLNode* insert(AVLNode* node, int key)
	{
		/*normal BST insertion*/
		AVLNode* t = NULL;
		if (node == NULL) {
			t = new AVLNode;
			t->data = key;
			t->height = 1;
			t->left = t->right = NULL;
			return t; // return the created node to assign the suit position 
		}
		if (key < node->data) {
			// go to the left
			//cout << key << "   ";
			node->left = insert(node->left, key);
		}
		else if (key > node->data) {
			// right 
			// note : insert rerurn an created new node :
			node->right = insert(node->right, key);
		}
		else { // Equal keys are not allowed in BST  
			return node;
		}

		// here after insert each node its hight will be changed so i should update hight 
		// max bett hl , hr ,,, get the hight of node by taking the max (hight of its child) + 1
		node->height = GetHight(node);// +1 the cuurent node


		//after we get all nodes hight updated we calc the balance factor of each node at return time
		int balanceFactor = getbalance(node);
		/* after get the balance factor of current node we must chcek balanced
		 4 cases (LL,RR,LR,RL)
		 1 . LL


			Rotations only applied on 3 nodes
			suppose we have 3 nodes and sign of node 1 + "left", and node 2 + it mean we insert at left of node 2
			" then it LL rotation "

			node 1 + , node 2 - => LR rotation (mean we insert at the right of the node 2)
			conclusion :
				BF > 1 ,left is bigger
				BF < -1 , right branch is bigger
		*/
		if (balanceFactor > 1) {
			// mean this node what i stand on it "impalance"
			if (key < node->left->data) {
				// we can do it (balance factor(node) == 2 && balance factor(node->left) == 1)
				// LL case 
				return LLRotation(node);
			}
			else if (key > node->left->data) {
				// LR case
				//return LRRotation(node);
			}
		}
		else if (balanceFactor < -1) {
			if (key > node->right->data) {
				//RR case 
				//return RRRotation();
			}
			else if (key < node->right->data) {
				//RL case
				//return RLRotation();
			}
		}
		return node;
	}
};
