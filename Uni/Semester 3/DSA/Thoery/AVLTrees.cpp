#include <iostream>
using namespace std;

class avl {
public:
    int val;
    avl* left;
    avl* right;
    int height;

    avl() : val(0), left(nullptr), right(nullptr), height(1) {}
    avl(int v) : val(v), left(nullptr), right(nullptr), height(1) {}

    int getHeight(avl* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    int getBalance(avl* node) {
        if (node == nullptr) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    void updateHeight(avl* node) {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }

    avl* leftLeft(avl* root) {
        avl* x = root->left;
        avl* t2 = x->right;

        x->right = root;
        root->left = t2;

        updateHeight(root);
        updateHeight(x);
        return x;
    }

    avl* rightRight(avl* root) {
        avl* x = root->right;
        avl* t2 = x->left;

        x->left = root;
        root->right = t2;

        updateHeight(root);
        updateHeight(x);
        return x;
    }

    avl* leftRight(avl* root) {
        root->left = rightRight(root->left);
        return leftLeft(root);
    }

    avl* rightLeft(avl* root) {
        root->right = leftLeft(root->right);
        return rightRight(root);
    }

    avl* insert(avl* root, int key) {
        if (root == nullptr)
            return new avl(key);

        if (key < root->val)
            root->left = insert(root->left, key);
        else if (key > root->val)
            root->right = insert(root->right, key);
        else
            return root;

        updateHeight(root);
        int b = getBalance(root);

        if (b > 1 && key < root->left->val)
            return leftLeft(root);
        if (b < -1 && key > root->right->val)
            return rightRight(root);
        if (b > 1 && key > root->left->val)
            return leftRight(root);
        if (b < -1 && key < root->right->val)
            return rightLeft(root);

        return root;
    }

    avl* minValueNode(avl* node) {
        avl* curr = node;
        while (curr->left != nullptr)
            curr = curr->left;
        return curr;
    }

    avl* deleteNode(avl* root, int key) {
        if (root == nullptr)
            return root;

        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else {
            if (root->left == nullptr || root->right == nullptr) {
                avl* temp = root->left ? root->left : root->right;
                if (temp == nullptr) {
                    delete root;
                    return nullptr;
                } else {
                    avl* curr = temp;
                    delete root;
                    return curr;
                }
            } else {
                avl* temp = minValueNode(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }

        updateHeight(root);
        int b = getBalance(root);

        if (b > 1 && getBalance(root->left) >= 0)
            return leftLeft(root);
        if (b > 1 && getBalance(root->left) < 0)
            return leftRight(root);
        if (b < -1 && getBalance(root->right) <= 0)
            return rightRight(root);
        if (b < -1 && getBalance(root->right) > 0)
            return rightLeft(root);

        return root;
    }
};
