#include "AVLTree.h"

AVLNode *AVLTree::remove_(AVLNode *p, string key) {
  if (p == nullptr) {
    return nullptr;
  }

  // Normal BST deletion
  if (key < p->key.getHandel()) {
    p->left = remove_(p->left, key);
  } else if (key > p->key.getHandel()) {
    p->right = remove_(p->right, key);
  } else {
    // Node with only one child or no child
    if (p->left == nullptr || p->right == nullptr) {
      AVLNode *temp = (p->left != nullptr) ? p->left : p->right;

      // No child case
      if (temp == nullptr) {
        temp = p;
        p = nullptr;
      } else {      // One child case
        *p = *temp; // Copy the contents of the non-empty child
      }

      delete temp;
    } else {
      // Node with two children
      AVLNode *temp = InSucc(p->right);
      p->key.MakeCopy(temp->key);
      p->right = remove_(p->right, temp->key.getHandel());
    }
  }

  // If the tree had only one node, then return
  if (p == nullptr) {
    return nullptr;
  }

  // Update height
  p->height = 1 + std::max(height(p->left), height(p->right));

  // Check balance factor
  int balanceFactor = getBalance(p);

  // Perform rotations if needed
  if (balanceFactor > 1) {
    if (key < p->left->key.getHandel()) {
      return rightRotate(p);
    } else if (key > p->left->key.getHandel()) {
      p->left = leftRotate(p->left);
      return rightRotate(p);
    }
  } else if (balanceFactor < -1) {
    if (key > p->right->key.getHandel()) {
      return leftRotate(p);
    } else if (key < p->right->key.getHandel()) {
      p->right = rightRotate(p->right);
      return leftRotate(p);
    }
  }

  return p;
}

AVLNode *AVLTree::search_(AVLNode *root, User key) {
  if (root == NULL || root->key.getHandel() == key.getHandel())
    return root;

  // Key is greater than root's key
  if (root->key.getHandel() < key.getHandel())
    return search_(root->right, key);

  // Key is smaller than root's key
  return search_(root->left, key);
}
AVLNode *AVLTree::search_(AVLNode *root, string key) {
  if (root == NULL || root->key.getHandel() == key)
    return root;

  // Key is greater than root's key
  if (root->key.getHandel() < key)
    return search_(root->right, key);

  // Key is smaller than root's key
  return search_(root->left, key);
}
