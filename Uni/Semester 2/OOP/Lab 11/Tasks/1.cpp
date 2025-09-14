#include <iostream>
using namespace std;

template <typename T>
void swapValue(T &a, T &b){
    T temp=a;
    a=b;
    b=temp;
}

int main(){
    int a = 5, b = 10;
    cout<<"Before swap: a = "<<a<<", b = "<<b<<endl;
    swapValue(a, b);
    cout<<"After swap: a = "<<a<<", b = "<<b<<endl<<endl;
    float x = 3.5f, y = 7.8f;
    cout<<"Before swap: x = "<<x<<", y = "<<y<<endl;
    swapValue(x, y);
    cout<<"After swap: x = "<<x<<", y = "<<y<<endl<<endl;
    char ch1 = 'A', ch2 = 'Z';
    cout<<"Before swap: ch1 = '"<<ch1<<"', ch2 = '"<<ch2<<"'"<<endl;
    swapValue(ch1, ch2);
    cout<<"After swap: ch1 = '"<<ch1<<"', ch2 = '"<<ch2<<"'"<<endl;

    return 0;
}