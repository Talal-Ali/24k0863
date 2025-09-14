#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string entry;

    ofstream diaryFile("diary.txt", ios::app);

    if (!diaryFile) {
        cerr << "Error opening diary.txt for writing." << std::endl;
        return 1;
    }

    std::cout << "Start writing your diary entry (type 'exit' to finish):" << std::endl;

    while (true) {
        getline(std::cin, entry);

        if (entry == "exit") {
            break;
        }

        diaryFile << entry << std::endl;
    }

    diaryFile.close();
    cout << "Diary entry saved to diary.txt." << std::endl;

}
