#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Pair {
    private:
    T1 first;
    T2 second;

    public:
    Pair(const T1& f, const T2& s) : first(f), second(s) {}
    void display() const {
        cout<<"Pair: ("<<first<<", "<<second<<")"<<endl;
    }
    T1 getFirst() const { return first; }
    T2 getSecond() const { return second; }
    void setFirst(const T1& f) { first = f; }
    void setSecond(const T2& s) { second = s; }
};

int main() {
    Pair<int, string> p1(5, "Hello");
    p1.display();
    Pair<double, int> p2(3.14, 42);
    p2.display();
    Pair<char, bool> p3('A', true);
    p3.display();

    return 0;
}