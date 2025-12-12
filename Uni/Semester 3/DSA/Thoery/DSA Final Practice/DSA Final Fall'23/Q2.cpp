#include<iostream>
using namespace std;

class Entry{
public:
    int n;
    bool used;
    bool deleted;
    Entry():n(0), used(false), deleted(false){}
    Entry(int a):n(a), used(false), deleted(false){}
};

class Hash{
public:
    Entry* h;
    int size;
    Hash();
    Hash(int s)
    {
        size = s;
        h = new Entry[size];
    }
    int hashfunction(Entry e)
    {
        int ha;
        ha = (e.n + 15)%4;
        return ha;
    }
    void add(Entry k)
    {
        for(int i = 0; i<size; i++)
        {
            int idx = (hashfunction(k)+i) % size; // Linear Probing
            if(!h[i].used || h[i].deleted)
            {
                h[i].n = k.n;
                h[i].used = true;
                h[i].deleted = false;
                return;
            }
        }
    }
    void removed(Entry k)
    {
        
    }
};