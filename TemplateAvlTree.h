
#include <iostream>
#include <queue>

template <typename T>
struct AVLNode {
    T data;
    AVLNode* left;
    AVLNode* right;
    int height;
};

template <typename T>
class AVLTree {
public:
    AVLNode<T>* root = nullptr;

    int GetHight(AVLNode<T>* p) {
        int hl, hr;
        hl = (p && p->left) ? p->left->height : 0;
        hr = (p && p->right) ? p->right->height : 0;

        return hl > hr ? hl + 1 : hr + 1;
    }

    int getbalance(AVLNode<T>* node) {
        int hl, hr;
        hl = node && node->left ? node->left->height : 0;
        hr = node && node->right ? node->right->height : 0;

        return hl - hr;
    }

    AVLNode<T>* LLRotation(AVLNode<T>* p) {
        AVLNode<T>* left_p = p->left;
        AVLNode<T>* right_left_p = p->left->right;

        p->left = right_left_p;
        left_p->right = p;

        p->height = GetHight(p);
        left_p->height = GetHight(left_p);

        if (root == p)
            root = left_p;

        return left_p;
    }

    AVLNode<T>* LRRotation(AVLNode<T>* p) {
        AVLNode<T>* pl = p->left;
        AVLNode<T>* plr = pl->right;

        p->left = plr->right;
        pl->right = plr->left;

        plr->left = pl;
        plr->right = p;

        pl->height = GetHight(pl);
        p->height = GetHight(p);
        plr->height = GetHight(plr);

        if (p == root) root = plr;
        return plr;
    }

    AVLNode<T>* RRRotation(AVLNode<T>* p) {
        AVLNode<T>* pr = p->right;
        AVLNode<T>* prl = pr->left;

        pr->left = p;
        p->right = prl;

        p->height = GetHight(p);
        pr->height = GetHight(pr);

        if (root == p) {
            root = pr;
        }
        return pr;
    }

    AVLNode<T>* RLRotation(AVLNode<T>* p) {
        AVLNode<T>* pr = p->right;
        AVLNode<T>* prl = pr->left;

        pr->left = prl->right;
        p->right = prl->left;

        prl->right = pr;
        prl->left = p;

        pr->height = GetHight(pr);
        p->height = GetHight(p);
        prl->height = GetHight(prl);

        if (root == p) {
            root = prl;
        }
        return prl;
    }

    void preOrder(AVLNode<T>* root) {
        if (root != nullptr) {
            std::cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void Levelorder(AVLNode<T>* p) {
        std::queue<AVLNode<T>*> q;
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

    void Inorder(AVLNode<T>* p) {
        if (p) {
            Inorder(p->left);
            std::cout << p->data << ", ";
            Inorder(p->right);
        }
    }

    AVLNode<T>* insert(AVLNode<T>* node, T key) {
        AVLNode<T>* t = nullptr;
        if (node == nullptr) {
            t = new AVLNode<T>;
            t->data = key;
            t->height = 1;
            t->left = t->right = nullptr;
            return t;
        }
        if (key < node->data) {
            node->left = insert(node->left, key);
        }
        else if (key > node->data) {
            node->right = insert(node->right, key);
        }
        else {
            return node;
        }

        node->height = GetHight(node);

        int balanceFactor = getbalance(node);

        if (balanceFactor > 1) {
            if (key < node->left->data) {
                return LLRotation(node);
            }
            else if (key > node->left->data) {
                return LRRotation(node);
            }
        }
        else if (balanceFactor < -1) {
            if (key > node->right->data) {
                return RRRotation(node);
            }
            else if (key < node->right->data) {
                //return RLRotation();
            }
        }
        return node;
    }

    AVLNode<T>* Delete(AVLNode<T>* p, T key) {
        if (p == nullptr) {
            return nullptr;
        }

        if (p->left == nullptr && p->right == nullptr) {
            if (p == root) {
                root = nullptr;
            }
            delete p;
            return nullptr;
        }

        if (key < p->data) {
            p->left = Delete(p->left, key);
        }
        else if (key > p->data) {
            p->right = Delete(p->right, key);
        }
        else {
            AVLNode<T>* q;
            if (GetHight(p->left) > GetHight(p->right)) {
                q = InPre(p->left);
                p->data = q->data;
                p->left = Delete(p->left, q->data);
            }
            else {
                q = InSucc(p->right);
                p->data = q->data;
                p->right = Delete(p->right, q->data);
            }
        }

        p->height = GetHight(p);

        int balanceFactor = getbalance(p);

        if (balanceFactor > 1) {
            if (key < p->left->data) {
                return LLRotation(p);
            }
            else if (key > p->left->data) {
                return LRRotation(p);
            }
        }
        else if (balanceFactor < -1) {
            if (key > p->right->data) {
                return RRRotation(p);
            }
            else if (key < p->right->data) {
                //return RLRotation();
            }
        }
        return p;
    }
};
