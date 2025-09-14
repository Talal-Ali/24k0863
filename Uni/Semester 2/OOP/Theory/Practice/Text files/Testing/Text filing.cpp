#include <iostream>
#include <string>
#include <fstream>
#include<vector>
using namespace std;

class Note{
	string name;
	string id;
	
	public:
		Note(string n, string i):name(n), id(i){}
		void openfile(string n){
			fstream file;
			file.exceptions(fstream::failbit | fstream::badbit);
			try{
				file.open(n,ios::out|ios::app|ios::in);
				
			}
			catch(ifstream::failure &e)
			{
				cout<<"File not found"<<endl;
				cerr<<"Exception: "<<e.what()<<endl;
			}
			file<<name<<", "<<id<<endl;
			file.close();
		}
};
void appending(string n, string find, string replacement){
	ifstream file;
	file.open(n, ios::in);
	vector<string> lines;
	string line;
	while(getline(file, line)){
		if(line.find(find) != string::npos){
			line = replacement;
		}		
		lines.push_back(line);
	}
	file.close();
	
	ofstream ofile;
	ofile.open(n, ios::out|ios::trunc);
	for(const string &l:lines){
		ofile<<l<<endl;
	}
	ofile.close();
}
int main(){
//	Note n("ABC", "123");
//	Note n2("DEF", "345");
//	n.openfile("example.txt");
//	n2.openfile("example.txt");
appending("example.txt", "ABC", "JKL");

}