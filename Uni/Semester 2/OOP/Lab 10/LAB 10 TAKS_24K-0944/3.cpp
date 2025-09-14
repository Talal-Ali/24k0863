#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string name, email;
    char more;

    ofstream signupFile("signup.txt", ios::app);

    if (!signupFile) {
        cerr << "Error opening signup.txt for writing." << endl;
        return 1;
    }

    do {
        cout << "Enter your name: ";
        getline(cin, name);

        cout << "Enter your email: ";
        getline(cin, email);

        signupFile << "Name: " << name << ", Email: " << email << endl;

        cout << "Do you want to register another person? (y/n): ";
        cin >> more;
    } while (tolower(more) == 'y');

    signupFile.close();
    cout << "All registrations saved to signup.txt." << endl;

}
