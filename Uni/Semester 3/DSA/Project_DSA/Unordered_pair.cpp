#pragma once
#include<iostream>
using namespace std;
class unordered
{
    public:
        string a;
        string b;
        unordered() {}
        unordered(string first, string second)
        {
            if(first<second)
            {
                first = a;
                second = b;
            }
            else
            {
                first = b;
                second = a;
            }
        }
        bool operator==(unordered &other)
        {
            return (other.a==a && other.b == b);
        }

        

};
class Hash
{
    size_t operator()(unordered &un)
    {
        return stringHash(un.a + "#" + un.b);
    }

    int stringHash(const string& a)
        {
            int hash = 0;
            int prime = 37;
            for(char c: a)
            {
                hash = (hash* prime+ (unsigned char)c) % 10000007;
            }
            return hash;
        }
};

