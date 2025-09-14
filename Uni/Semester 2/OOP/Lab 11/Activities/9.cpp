#include <iostream>
using namespace std;

template <typename T>
class Division{
    public:
    void divide(T a, T b){
        try{
            if(!b) throw b;
            cout<<"Result: "<<a/b<<endl;
        }
        catch(T b){
            cout<<"Can't divide by zero"<<endl;
        }
    }
};

int main(){
    Division <double> d1;
    d1.divide(15.5, 0.0);
    Division<int> d2;
    d2.divide(15,0);
    Division <double> d3;
    d3.divide(12.56,17.92);
    return 0;
}