#include <iostream>
using namespace std;

int main() {
    int students = 5, subjects = 4;

    int **marks = new int*[students];
    for (int i = 0; i < students; i++) marks[i] = new int[subjects];

    cout << "Enter marks of " << students << " students in " << subjects << " subjects:\n";
    for (int i = 0; i < students; i++) {
        cout << "Student " << i + 1 << ":\n";
        for (int j = 0; j < subjects; j++) {
            cout << "  Subject " << j + 1 << ": ";
            cin >> marks[i][j];
        }
    }

    int *totalMarks = new int[students];
    int topperIndex = 0;
    for (int i = 0; i < students; i++) {
        totalMarks[i] = 0;
        for (int j = 0; j < subjects; j++) totalMarks[i] += marks[i][j];
        cout << "Total marks of Student " << i + 1 << " = " << totalMarks[i] << endl;
        if (totalMarks[i] > totalMarks[topperIndex]) topperIndex = i;
    }

    cout << "\nAverage marks of each subject:\n";
    for (int j = 0; j < subjects; j++) {
        float sum = 0;
        for (int i = 0; i < students; i++) sum += marks[i][j];
        cout << "Subject " << j + 1 << " Average = " << (sum / students) << endl;
    }

    cout << "\nTopper Student is Student " << (topperIndex + 1)
         << " with total marks = " << totalMarks[topperIndex] << endl;

    for (int i = 0; i < students; i++) delete[] marks[i];
    delete[] marks;
    delete[] totalMarks;
}
