#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("story.txt");

    if (!inputFile) {
        cerr << "Error opening story.txt." << endl;
        return 1;
    }

    string line;
    
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string word;

        while (iss >> word) {
            cout << word << endl;
        }
    }

    inputFile.close();
}
