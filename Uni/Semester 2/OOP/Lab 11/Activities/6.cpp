#include <iostream>
using namespace std;

void exceptionHandler(int test){
    try{
        if(test) throw test;
        else throw "Value is zero";
    }
    catch(int i){
        cout<<"Caught Exception: "<<i<<endl;
    }
    catch(const char *str){
        cout<<"Caught a string: ";
        cout<<str<<endl;
    }
};

int main(){
    cout<<"Start"<<endl;
    exceptionHandler(1);
    exceptionHandler(2);
    exceptionHandler(0);
    exceptionHandler(3);
    return 0;
}