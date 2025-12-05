#include<iostream>
#include<math.h>
using namespace std;

class avl
{
public:
    int val;
    avl* left;
    avl* right;
    int height;
    avl():val(0), left(nullptr), right(nullptr), height(0){}
    avl(int v):val(v), left(nullptr), right(nullptr), height(0){}

    int getheight(avl* root)
    {
        if(root == nullptr){return 0;}
        return root->height;
    }
    int balance(avl* root)
    {
        int b = getheight(root->left) - getheight(root->right);
        return b;
    }
    void updateheight(avl* root)
    {
        root->height = 1 + max(getheight(root->left),getheight(root->right));
    }
    avl* leftleft(avl* root)
    {
        avl* x = root->left;
        avl* t2 = x->right;

        x->right = root;
        root->left = t2;

        updateheight(root);
        updateheight(x);
        return x;
    }
    avl* rightright(avl* root)
    {
        avl* x = root->right;
        avl* t2 = x->left;

        x->left = root;
        root->right = t2;

        updateheight(root);
        updateheight(x);
        return x;
    }
    avl* leftright(avl* root)
    {
        root->left = rightright(root);
        return leftleft(root);
    }
    avl* rightleft(avl* root)
    {
        root->right = leftleft(root);
        return rightright(root);
    }
    avl* insert(int n, avl* root)
    {
        if (root == nullptr)
            return new avl(n);

        if (n < root->val){
            root->left = insert(n, root->left);
        }
        else if (n > root->val)
        {
            root->right = insert(n, root->right);
        } 
        else
        {
            return root;
        }
        updateheight(root);
        int b = balance(root);
        //LL Case
        if(b>1 && n<root->left->val)
        {
            return leftleft(root);
        }
        //RR Case
        if(b<-1 && n>root->right->val)
        {
            return rightright(root);
        }
        //LR Case
        if(b>1 && n>root->left->val)
        {
            return leftright(root);
        }
        //RL CAse
        if(b<-1 && n<root->right->val)
        {
            return rightleft(root);
        }
        
        return root;
    }
    avl* deleteNodes(avl* root, int n)
    {
        if(root == nullptr){return nullptr;}
        if(n<root->val){root->left = deleteNodes(root->left, n);}
        else if(n>root->val){root->right = deleteNodes(root->right, n);}
        else{
            if(!root->left && !root->right)
            {
                delete root;
                return nullptr;
            }
            if(!root->left)
            {
                avl* temp = root->right;
                delete root;
                root = temp;
                return temp;
            }
            if(!root->right)
            {
                avl* temp = root->left;
                delete root;
                root = temp;
                return temp;
            }
            if(root->left && root->right)
            {
                avl* successor = root->right;
                while(successor->left)
                {
                    successor = successor->left;
                }
                root->val = successor->val;
                root->right = deleteNodes(root->right, successor->val);
            }
            
        }
        updateheight(root);
        int b = balance(root);
        if(b>1)
        {
            if(balance(root->left)>=0)
            {
                return leftleft(root);
            }
            else
            {
                return leftright(root);
            }
        }
        if(b<-1)
        {
            if(balance(root->right) <= 0)
            {
                return rightright(root);
            }
            else
            {
                return rightleft(root);
            }
        }

        return root;
    }

};