#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main() {
    ofstream logFile("system_log.txt", ios::app);

    if (!logFile) {
        cerr << "Error opening system_log.txt for writing." << endl;
        return 1;
    }

    time_t now = time(0);
    char* dt = ctime(&now);

    logFile << "System started at: " << dt;

    logFile.close();
    cout << "Log entry added to system_log.txt" << endl;

}
