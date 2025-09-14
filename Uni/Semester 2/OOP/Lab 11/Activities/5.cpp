#include <iostream>
using namespace std;

class MyException{
    public:
    string str;
    int num;

    MyException(string str, int n){
        this->str = str;
        num = n;
    }
};

int main(){
    int i;
    try{
        cout<<"Enter a positive number: ";
        cin>>i;
        if(i<0){
            throw MyException("Not Positive", i);
        }
    }
    catch (MyException e){
        cout<<e.str<<": ";
        cout<<e.num<<endl;
    }
}