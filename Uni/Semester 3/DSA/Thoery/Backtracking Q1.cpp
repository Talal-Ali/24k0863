/*
🟢 Level 1: Small Choices

Binary Strings of Length n
Generate all binary strings of length n.
Example for n=2: ["00","01","10","11"].

👉 Teaches: each position has 2 choices (0 or 1).
*/


#include <iostream>
#include <vector>
using namespace std;

void binaryStrings(int n, string current, vector<string> &result) {
    if (current.size() == n) {
        result.push_back(current);
        return;
    }

    binaryStrings(n, current + '0', result);
    binaryStrings(n, current + '1', result);
}

int main() {
    int n = 4;  
    vector<string> result;
    
    binaryStrings(n, "", result);

    for (auto &s : result) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
