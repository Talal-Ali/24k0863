#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream file("draft.txt", ios::in | ios::out);

    if (!file.is_open()) {
        cerr << "ERROR OPENING FILE!";
        return 1;
    }

    char ch;
    while (file.get(ch)) {
        if (ch == 't') {
            streampos pos = file.tellg(); 
            char next[2];

            file.get(next[0]);
            file.get(next[1]);

            if (next[0] == 'e' && next[1] == 'h') {
                file.seekp(pos - (streampos)1);       
                file.write("the",3);  
                cout << "'teh' corrected to 'the'\n";
                break;
            } else {
                file.seekg(pos);        
            }
        }
    }

    file.close(); 

}
