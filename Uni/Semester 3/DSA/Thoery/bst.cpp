#include<iostream>
using namespace std;

class bst{
public:
    int val;
    bst* left;
    bst* right;
    int top;
    bst(): val(0), left(nullptr), right(nullptr), top(-1){}
    bst(int v): val(v), left(nullptr), right(nullptr), top(-1){}
    

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

    void push(int v, int* arr, int size)
    {
        if(top<size)
        {
            top++;
            arr[top] = v;
        }
        return;

    }
    void bsttostack(bst* root, int * arr, int size)
    {
        if(root == nullptr)
        {
            return;
        }
        push(root->val, arr, size);


        bsttostack(root->left, arr, size);
        bsttostack(root->right, arr, size);
    }
    void pop(int* arr, int size)
    {
        if(top== -1)
        {
            return;
        }
        arr[top]= -1;
        top--;

    }
    int tsum(bst*& root, int target, int*& arr, int size, int& t)
    {
        int current = root->val;
        if(root == nullptr)
        {
            return 0;
        }
        if(root->left == nullptr && root->left == nullptr && target == 0)
        {
            for(int i=0; i<size; i++)
            {
                t++;
                cout<<arr[i]<<endl;
            }
            return 0;
        }
        
        int l = tsum(root->left, target - current, arr, size, t);
        root->pop(arr, size);
        int r = tsum(root->right, target- current, arr, size, t);
        root->pop(arr, size);
        return target;
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
    int* arr = new int[7];
    int size = 7;

    bst* root= new bst(10);
    root = insert(3, root);
    root = insert(12, root);
    root = insert(1, root);
    root = insert(2, root);
    root = insert(4, root);
    root = insert(14, root);

    int t = 0;
    root->bsttostack(root, arr, size);
    root->tsum(root, 24, arr, size, t);
    root->printTree(root);
}