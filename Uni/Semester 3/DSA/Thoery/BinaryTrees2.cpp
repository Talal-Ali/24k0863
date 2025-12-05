#include <iostream>
using namespace std;

class BinaryTree{
public:
    int val;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree():val(0), left(nullptr), right(nullptr){}
    BinaryTree(int v):val(v), left(nullptr), right(nullptr){}

    BinaryTree* insert(int n, BinaryTree* root)
    {
        if (root == nullptr)
            return new BinaryTree(n);

        if (n < root->val)
            root->left = insert(n, root->left);
        else if (n > root->val)
            root->right = insert(n, root->right);

        return root;
    }

    void InorderTreeToArrayWithNull(BinaryTree* root, int* arr, int& i, int n)
    {
        if (i >= n) return;

        if (root == nullptr)
        {
            arr[i++] = -812371837;
            return;
        }

        InorderTreeToArrayWithNull(root->left, arr, i, n);
        arr[i++] = root->val;
        InorderTreeToArrayWithNull(root->right, arr, i, n);
    }


    void printArray(int* arr, int size)
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << ", ";
        cout << endl;
    }
    BinaryTree* deleteNode(BinaryTree* root, int s)
    {
        if(root == nullptr)
        {
            return nullptr;
        }
        if(root->val>s){root->left = deleteNode(root->left, s);}
        else if(root->val<s){root->right = deleteNode(root->right, s);}
        if(root->val == s)
        {
            if(root->left == nullptr && root->right == nullptr)
            {
                delete root;
                return nullptr;
            }
            if(root->left == nullptr && root->right != nullptr)
            {
                BinaryTree* temp = root->right;
                delete root;
                root = temp;
                return temp;
            }
            else if(root->left != nullptr && root->right == nullptr)
            {
                BinaryTree* temp = root->left;
                delete root;
                root = temp;
                return temp;
            }
            if(root->left != nullptr && root->right != nullptr)
            {
                BinaryTree* successor = root->right;
                while(successor->left){successor = successor->left;}
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        }
        return root;
    }
};



int main()
{
    BinaryTree* r1 = new BinaryTree(17);
    r1 = r1->insert(3, r1);
    r1 = r1->insert(1, r1);
    r1 = r1->insert(15, r1);
    r1 = r1->insert(64, r1);
    r1 = r1->insert(53, r1);
    r1 = r1->insert(75, r1);

    int size = 20;
    int* arr = new int[size];
    for(int i= 0; i<size; i++)
    {
        arr[i] = 0;
    }
    int i = 0;

    r1->InorderTreeToArrayWithNull(r1, arr, i, size);
    r1->printArray(arr, size);

    return 0;
}

