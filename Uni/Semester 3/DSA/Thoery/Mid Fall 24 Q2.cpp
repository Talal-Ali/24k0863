#include<iostream>

using namespace std;

class stack{
    int *data;
    int size = 0;
public:
    stack(int s)
    {
        size = s;
        data = new int[size];
    }
    ~stack()
    {
        delete[] data;
    }
    stack(stack &s)
    {
        size = s.size;
        data = new int[size];
        for(int i = 0; i< size; i++)
        {
            data[i] = s.data[i];
        }
    }
    void add(int a)
    {
        size++;
        int i;
        int *d = new int[size];
        for( i= 0; i< size-1; i++)
        {
            d[i] = data[i];
        }
        d[i] = a; 
        delete[] data;
        data = d;
    }
    void remove()
    {
        if(size == 0){return;}
        if(size == 1){delete [] data; size--; return;}
        size--;
        int *d = new int[size];
        for(int i = 0; i<size; i++)
        {
            d[i] = data[i];
        }
        delete [] data;
        data = d;
    }
    void reverse()
    {
        for(int i= 0; i<size; i++)
        {
            int temp = data[i];
            data[i] =  data[size-i-1];
            data[size-i-1] = temp;
        }
    }
};
