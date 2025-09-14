#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

int main() {
    std::ifstream inputFile("article.txt");
    std::ofstream reportFile("report.txt");
    if (!inputFile) {
        std::cerr << "Could not open article.txt for reading.\n";
        return 1;
    }
    if (!reportFile) {
        std::cerr << "Could not open report.txt for writing.\n";
        return 1;
    }
    std::string line;
    size_t totalChars = 0;
    size_t totalWords = 0;
    size_t totalLines = 0;
    size_t punctuationCount = 0;

    while (std::getline(inputFile, line)) {
        totalLines++;
        totalChars += line.length();

        bool inWord = false;
        for (char ch : line) {
            if (std::ispunct(ch)) {
                punctuationCount++;
            }

            if (std::isspace(ch)) {
                inWord = false;
            } else if (!inWord) {
                inWord = true;
                totalWords++;
            }
        }
    }

    totalChars += totalLines; 
    reportFile << "Article Quality Report\n";
    reportFile << "-----------------------\n";
    reportFile << "Total Characters       : " << totalChars << "\n";
    reportFile << "Total Words            : " << totalWords << "\n";
    reportFile << "Total Lines            : " << totalLines << "\n";
    reportFile << "Punctuation Marks Count: " << punctuationCount << "\n";
    inputFile.close();
    reportFile.close();
    std::cout << "Report has been written to report.txt\n";

}
