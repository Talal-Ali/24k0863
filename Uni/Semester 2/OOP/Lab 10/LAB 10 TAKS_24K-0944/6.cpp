#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    
    ifstream alpha("alphabet.txt");

    if(!alpha){
        cerr << "ERROR COULDNT OPEN FILE";
        return 1;
    }

    char ch;
    int c=0;

    while (alpha.get(ch)){
        if(isupper(ch))
            c++;
    }

    alpha.close();
    cout << "The number of capital alphabets are: " << c;

}