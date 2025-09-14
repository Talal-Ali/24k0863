    #include<iostream>
#include<fstream>
using namespace std;

int main()
{
    
    ofstream greet;
    greet.open("greetings.txt");

    if(!greet){
        cerr << "Error: Cannot open file!";
        return 1;
    }else{
        cout << "Enter your name: ";
        string n; cin >> n;

        greet << "Dear " << n << " \n";
        greet << "Have a nice day!\n";
        greet << "Best Regards!"; 
    }

}