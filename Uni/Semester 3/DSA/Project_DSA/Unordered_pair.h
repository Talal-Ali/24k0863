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
        bool operator==(const unordered &other) const
        {
            return (other.a==a && other.b == b);
        }

        

};


