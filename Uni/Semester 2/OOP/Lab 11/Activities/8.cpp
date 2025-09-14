#include <iostream>
using namespace std;

void exceptionHandler(int test){
    try{
        if(test==0) throw test;
        if(test==1) throw "a";
        if(test==2) throw 123.23;
    }
    catch(int i){
        cout<<"Caught an integer"<<endl;
    }
    catch(...){
        cout<<"Caught One!"<<endl;
    }
}

int main(){
    cout<<"Start"<<endl;
    exceptionHandler(0);
    exceptionHandler(1);
    exceptionHandler(2);
    cout<<"End"<<endl;

    return 0;
}