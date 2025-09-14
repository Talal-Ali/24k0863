#include<iostream>
using namespace std;
class Rectangle{
double length, width;
public:
    Rectangle(double l=0, double w=0) : length(l), width(w) {}
    friend double Area(Rectangle& r){
        return r.length*r.width;
    }
};
int main()
{
    Rectangle r(2.5,4);
    cout << "The area of the Rectangle " << Area(r) << endl;
}