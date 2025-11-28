#include<iostream>
using namespace std;

class bst{
public:
    int val;
    bst* left;
    bst* right;
    bst(): val(0), left(nullptr), right(nullptr){}
    bst(int v): val(v), left(nullptr), right(nullptr){}
    

    void printTree(bst* root, string prefix = "", bool isLeft = true) {
        if (!root) return;

        // Print the current node with appropriate prefix
        cout << prefix;

        cout << (isLeft ? "├── " : "└── ");
        cout << root->val << endl;

        // Prepare prefix for children
        string newPrefix = prefix + (isLeft ? "│   " : "    ");

        // Left child
        if (root->left)
            printTree(root->left, newPrefix, true);
        else if (root->right)  // If right exists but left doesn't, we show placeholder
            cout << newPrefix << "├── " << "null" << endl;

        // Right child
        if (root->right)
            printTree(root->right, newPrefix, false);
        else if (root->left)
            cout << newPrefix << "└── " << "null" << endl;
    }

};
bst* insert(int v, bst* root)
    {
        
        if(root == nullptr)
        {
            root = new bst(v);
            return root;
        }
        if(root->val>v)
        {
            root->left = insert(v, root->left);
        }
        if(root->val<v)
        {
            root->right = insert(v, root->right);
        }
        return root;

    }


int main()
{
    bst* root= new bst(10);
    root = insert(3, root);
    root = insert(12, root);

    root->printTree(root);
}