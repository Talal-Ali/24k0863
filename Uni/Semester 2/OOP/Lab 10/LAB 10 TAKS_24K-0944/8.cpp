#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream articleFile("article.txt");

    if (!articleFile) {
        cerr << "Error opening article.txt." << endl;
        return 1;
    }

    articleFile.seekg(0, ios::end);      
    streampos halfwayPoint = articleFile.tellg() / 2;  

    articleFile.seekg(halfwayPoint);        

    string line;
    int linesPrinted = 0;

    cout << "Previewing middle of the article (10 lines):\n\n";

    while (linesPrinted < 10 && getline(articleFile, line)) {
        cout << line << endl;
        ++linesPrinted;
    }

    articleFile.close();

}
