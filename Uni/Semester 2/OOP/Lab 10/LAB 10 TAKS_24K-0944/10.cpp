#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    
    fstream logfile("backup.txt",ios::app);
    if(!logfile.is_open()){
        cerr << "ERROR";
        return 1;
    }

    cout << "Enter the login message('exit' to quit): ";
    string msg;

    while(true){
        getline(cin,msg);
        if(msg == "exit"){
            break;
        }
        logfile << msg << "\n";
        streampos size = logfile.tellg();
        cout << "Current file size: " << size << endl;
    }

    logfile.close();

}