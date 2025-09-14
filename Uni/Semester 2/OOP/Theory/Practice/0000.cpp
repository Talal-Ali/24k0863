#include<iostream>
using namespace std;

class Example {
    int x, y;
public:
    Example() {
        x = 0; y = 0;
    }
    Example(int a) {
        x = a; y = 0;
    }
    Example(int a, int b) {
        x = a; y = b;
    }
    void show() {
        cout << "x: " << x << ", y: " << y << endl;
    }
};

int main() {
    Example e1;
    Example e2(5);
    Example e3(10, 20);

    e1.show();
    e2.show();
    e3.show();
}
