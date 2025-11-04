#include<iostream>
using namespace std;

template<typename T1>
class BinaryTreeNode
{
    T1 data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

public:
    BinaryTreeNode():data(T1()), left(nullptr), right(nullptr){}
    BinaryTreeNode(T1 d): data(d), left(nullptr), right(nullptr){}
    BinaryTreeNode *getleft(){return left;}
    BinaryTreeNode *getright(){return right;}
    void setleft (BinaryTreeNode *L){left = L;}
    void setright (BinaryTreeNode *R){right = R;}
    T1 getData(){return data;}
    void setData(T1 d){data = d;}

    void print_inorder(BinaryTreeNode* root)
    {
        if(root == nullptr) return;
        print_inorder(root->left);
        cout<<root->data<<" ";
        print_inorder(root->right);
    }
    void array_to_binary_tree_unordered(T1* arr, BinaryTreeNode*& root, int i, int n)
    {
        if (i >= n)
            return;

        root = new BinaryTreeNode(arr[i]);
        array_to_binary_tree_unordered(arr, root->left, 2 * i + 1, n);
        array_to_binary_tree_unordered(arr, root->right, 2 * i + 2, n);
    }
    void array_to_binary_tree(T1* arr, BinaryTreeNode*& root, int start, int end)
    {
        if(start>end){return;}
        int mid = (start +end) /2;
        root = new BinaryTreeNode(arr[mid]);
        array_to_binary_tree(arr, root->left, start, mid-1);
        array_to_binary_tree(arr, root->right, mid+1, end);
    }
    void binary_tree_to_array(T1* arr, BinaryTreeNode* &root, int i, int n)
    {
        if(i>=n){return;}
        if(root != nullptr)
        {
            arr[i] = root->getData();
        }
        else
        {
            if constexpr (std::is_same<T1, string>::value)
            {
                arr[i] = "Null pointer";
            }
            else if constexpr (std::is_same<T1, float>::value)
            {
                arr[i] = -2731328.0f;
            }
            else
            {
                arr[i] = static_cast<T1>(-2731328);
            }
            return;

        }
        binary_tree_to_array(arr,root->left,2 * i+1,n);
        binary_tree_to_array(arr,root->right,2 * i+2,n);
    }
    void addData(T1 val, BinaryTreeNode*& root)
    {
        if (root == nullptr)
        {
            root = new BinaryTreeNode(val);
            return;
        }
        if constexpr (std::is_same<T1, string>::value)
        {
            size_t vlen = val.length();
            size_t rlen = root->data.length();

            if (vlen < rlen)
                addData(val, root->left);
            else if (vlen > rlen)
                addData(val, root->right);
            else
            {
                if (val < root->data)
                    addData(val, root->left);
                else
                    addData(val, root->right);
            }
        }
        else
        {
            if (val < root->data)
                addData(val, root->left);
            else
                addData(val, root->right);
        }
    }
    BinaryTreeNode* smallest(BinaryTreeNode* root)
    {
        if(root == nullptr){return nullptr;}
        if(root->left == nullptr){return root;}
        return smallest(root->left);
    }
    BinaryTreeNode* maximum(BinaryTreeNode* root)
    {
        if(root == nullptr){return nullptr;}
        if(root->right==nullptr){return root;}
        return maximum(root->right);
    }
    
    int getHeight(BinaryTreeNode *root) {
        if (!root) return 0;
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        return (lh > rh ? lh : rh) + 1;
    }

    // Fixed tree printing function
    void printTree(BinaryTreeNode* root) {
        if (!root) {
            cout << "Tree is empty!" << endl;
            return;
        }
        
        int height = getHeight(root);
        
        // Print each level
        for (int level = 1; level <= height; level++) {
            // Print nodes
            printNodeLevel(root, level, 1, height);
            cout << endl;
            
            // Print slashes (except for last level)
            if (level < height) {
                printSlashLevel(root, level, 1, height);
                cout << endl;
            }
        }
    }

private:
    void printNodeLevel(BinaryTreeNode* node, int targetLevel, int currentLevel, int totalHeight) {
        if (!node) {
            if (currentLevel <= targetLevel) {
                printSpaces(1 << (totalHeight - currentLevel + 1));
            }
            return;
        }
        
        if (currentLevel == targetLevel) {
            int spaces = (1 << (totalHeight - targetLevel)) - 1;
            printSpaces(spaces);
            cout << node->data;
            printSpaces(spaces);
        } else {
            printNodeLevel(node->left, targetLevel, currentLevel + 1, totalHeight);
            printNodeLevel(node->right, targetLevel, currentLevel + 1, totalHeight);
        }
    }
    
    void printSlashLevel(BinaryTreeNode* node, int targetLevel, int currentLevel, int totalHeight) {
        if (!node) {
            if (currentLevel <= targetLevel) {
                printSpaces(1 << (totalHeight - currentLevel + 1));
            }
            return;
        }
        
        if (currentLevel == targetLevel) {
            int spaces = (1 << (totalHeight - targetLevel - 1)) - 1;
            int between = (1 << (totalHeight - targetLevel)) - 1;
            
            printSpaces(spaces);
            // Left slash
            if (node->left) cout << "/";
            else cout << " ";
            
            printSpaces(between);
            // Right slash  
            if (node->right) cout << "\\";
            else cout << " ";
            
            printSpaces(spaces);
        } else {
            printSlashLevel(node->left, targetLevel, currentLevel + 1, totalHeight);
            printSlashLevel(node->right, targetLevel, currentLevel + 1, totalHeight);
        }
    }
    
    void printSpaces(int count) {
        for (int i = 0; i < count; i++) {
            cout << " ";
        }
    }
};

int main()
{
    
    BinaryTreeNode<int> *root = nullptr;
    BinaryTreeNode<int> *root2= nullptr;
    BinaryTreeNode<int> tree;

    tree.addData(4, root);
    tree.addData(2, root);
    tree.addData(1, root);
    tree.addData(5, root);
    tree.addData(6, root);
    tree.addData(3, root);

    cout << "Inorder Traversal: ";
    tree.print_inorder(root);
    cout << endl << endl;
    
    cout << "Binary Tree Structure:" << endl;
    tree.printTree(root);
    
    
    BinaryTreeNode<int> *min = tree.smallest(root);
    BinaryTreeNode<int> *max = tree.maximum(root);
    cout<<endl;
    cout<<"Minimum = "<<min->getData()<<endl;
    cout<<"Maximum = "<<max->getData()<<endl;


    int *arr = new int[7];
    for(int i=0; i<7; i++)
    {
        arr[i] = i+1;
    }
    
    // BinaryTreeNode<int> t2;
    // t2.array_to_binary_tree(arr, root2, 0, 6);
    // t2.print_inorder(root2);
    // cout<<endl;
    // t2.printTree(root2);


    int arr2[10];
    tree.binary_tree_to_array(arr2, root, 0, 10);
    for(int i=0; i<10; i++)
    {
        cout<<arr2[i]<<",";
    }
    cout<<endl;
    delete [] arr;
    return 0;
}