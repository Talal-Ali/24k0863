#include <iostream>
using namespace std;

class Division{
    private:
    int numerator;
    int denominator;
    public:
    Division(int n, int d): numerator(n), denominator(d){}

    void divide(){
        try{
            if(denominator==0) throw "Division by zero not allowed";
            cout<<"Result: "<<numerator/denominator<<endl;
        }
        catch(const char* errorMsg) {
            cout << "Error: " << errorMsg << endl;
        }
    }
};

int main() {
    int n, d;
        cout << "Enter numerator: ";
    cin >> n;
    cout << "Enter denominator: ";
    cin >> d;
    
    Division div1(n, d);
    div1.divide();
    
    cout << "\nEnter numerator: ";
    cin >> n;
    cout << "Enter denominator: ";
    cin >> d;
    
    Division div2(n, d);
    div2.divide();
    
    return 0;
}