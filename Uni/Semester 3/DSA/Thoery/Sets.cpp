#include <iostream>
#include<stack>
#include<vector>
using namespace std;
//(2,4), (3,7), (8,12), (10,15), (17, 18)
class Set
{
    public:
        int a;
        int b;
        Set(int a1, int b1):a(a1), b(b1){}
};
int main()

{
    vector<Set> arr;
    Set a1(2,4);
    Set a2(3,7);
    Set a3(8,12);
    Set a4(10,15);
    Set a5(17,18);

    arr.push_back(a1);
    arr.push_back(a2);
    arr.push_back(a3);
    arr.push_back(a4);
    arr.push_back(a5);

    stack<Set> final;
    stack<int> temp;
    for(int i=0; i<5; i++)
    {
        temp.push(arr[i].a);
        temp.push(arr[i].b);

        if(i<4)
        {
            if(temp[i] < temp[i+1])
            {
                
                final = 
            }
        }
    }
}