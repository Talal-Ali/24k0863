#include<iostream>
using namespace std;

class Stack
{
    int *arr;
    int size;
    int top;
    public:
        Stack(int *ar, int size)
        {
            arr = new int[size];
            top = -1;
        }
        bool isEmpty()
        {
            if(top == -1){return true;}
            return false;
        }
        bool isFull()
        {
            if(top == size-1){return true;}
            return false;
        }
        void Push(int n)
        {
            if(isFull()){return;}
            arr[++top] = n;
        }
        void Pop()
        {
            if(isEmpty()){return;}
            arr[top] = 0;
            top--;
        }

};
