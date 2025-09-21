#include<iostream>
using namespace std;


class student
{
    int id;
    float gpa;
    string name;
    int age;

public:
    student(){}
    student(int i, float g, string n, int a):id(i), gpa(g), name(n), age(a){}
    float getgpa(){return gpa;}

};

void sort(student s[])
{
    student temp;
    bool swap = true;
    int length = sizeof(s)/sizeof(student);
    for(int i=0; i< length-1; i++)
    {
        for(int j =0; j<length - i -1; j++)
        {
            if(s[j].getgpa()<s[j+1].getgpa())
            {
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

void binarysearch(student s[], int length, float se) {
    int low = 0, high = length - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (s[mid].getgpa() == se) {
            cout << "Found student with GPA " << se << ": " << s[mid].getgpa() << endl;
            return;
        }
        else if (s[mid].getgpa() < se) {
            high = mid - 1; // search left (since descending order)
        }
        else {
            low = mid + 1; // search right
        }
    }
    cout << "Student with GPA " << se << " not found." << endl;
}