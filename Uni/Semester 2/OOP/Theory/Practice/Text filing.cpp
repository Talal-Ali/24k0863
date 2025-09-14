#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Note{
	string name;
	string id;
	
	public:
		Note(string n, string i):name(n), id(i){}
		void openfile(string n){
			fstream file(n, ios::app|ios::in|ios::out);
			try{
				file.open(n);
				
			}
			catch(ifstream::failure &e)
			{
				cout<<"File not found"<<endl;
				cerr<<"Exception: "<<e.what()<<endl;
			}
			file.close();
		}
};


int main(){
	Note n("ABC","123");
	n.openfile("example.txt");
}