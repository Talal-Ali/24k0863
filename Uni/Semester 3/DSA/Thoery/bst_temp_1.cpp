#include<iostream>
using namespace std;

class bst{
public:
    int val;
    bst* left;
    bst* right;

    bst(): val(0), left(nullptr), right(nullptr) {}
    bst(int v): val(v), left(nullptr), right(nullptr) {}

    void printTree(bst* root, string prefix = "", bool isLeft = true) {
        if (!root) return;
        cout << prefix << (isLeft ? "├── " : "└── ") << root->val << endl;
        string newPrefix = prefix + (isLeft ? "│   " : "    ");
        if (root->left) printTree(root->left, newPrefix, true);
        else if (root->right) cout << newPrefix << "├── " << "null" << endl;
        if (root->right) printTree(root->right, newPrefix, false);
        else if (root->left) cout << newPrefix << "└── " << "null" << endl;
    }

    // helper: recursive stack-based traversal + backtracking
    void findPathsHelper(bst* node, int target, int* arr, int size, int& top, int& found) {
        if (!node) return;
        if (top + 1 >= size) return;    // avoid overflow

        arr[++top] = node->val;          // push

        // leaf node: check sum
        if (!node->left && !node->right) {
            if (target == node->val) {
                for (int i = 0; i <= top; ++i) {
                    cout << arr[i] << (i == top ? "\n" : " ");
                }
                ++found;
            }
        } else {
            findPathsHelper(node->left,  target - node->val, arr, size, top, found);
            findPathsHelper(node->right, target - node->val, arr, size, top, found);
        }

        --top; // pop
    }

    // public wrapper: returns number of paths found
    int findPaths(int target, int* arr, int size) {
        int top = -1;
        int found = 0;
        findPathsHelper(this, target, arr, size, top, found);
        return found;
    }
};

bst* insert(int v, bst* root) {
    if(!root) return new bst(v);
    if(root->val > v) root->left = insert(v, root->left);
    else if(root->val < v) root->right = insert(v, root->right);
    return root;
}

int main() {
    int size = 7;
    int* arr = new int[size];

    bst* root= new bst(10);
    root = insert(3, root);
    root = insert(12, root);
    root = insert(1, root);
    root = insert(2, root);
    root = insert(4, root);
    root = insert(14, root);

    int found = root->findPaths(36, arr, size);  // stack-based root->leaf paths that sum to 24
    cout << "Paths found: " << found << endl;

    root->printTree(root);
    delete[] arr;
}