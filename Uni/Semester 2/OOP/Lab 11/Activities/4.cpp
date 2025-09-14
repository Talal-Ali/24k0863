#include <iostream>
using namespace std;

int main() {
    cout<<"Start "<<endl;

    try{
        cout<<"Inside try block"<<endl;
        throw 20;
        cout<<"This will not execute"<<endl;
    }
    catch(int i){
        cout<<"Caught an exception -- value is: ";
        cout<<i<<endl;
    }
    cout<<"End"<<endl;
    return 0;
}