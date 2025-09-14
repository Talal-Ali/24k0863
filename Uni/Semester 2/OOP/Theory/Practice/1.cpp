#include<iostream>

using namespace std;

class Place{
    string name;
    string date;

    public:
    Place(){}
    Place(string n, string d):name(n), date(d){}
    string getname(){
        return name;
    }
    string getdate(){
        return date;
    }
};


class Passport{
    string name;
    Place **p;
    int capacity;
    int i=0;
    public:
    Passport(){}
    void setname(string n){
        name = n;
    }
    void setcap(int c)
    {
        capacity = c;
    }
    void setPlace(string name, string date)
    {
        p= new Place*[capacity];
        
        if(i<capacity)
        {
            p[i] = new Place(name, date);
            i++;
        }
        else{
            cout<<"More places cannot be added"<<endl;
        }
    }
    void display()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Places: "<<endl;
        for(int j=0; j<i; j++)
        {
            cout<<"Name: "<<p[i]->getname()<<endl;
            cout<<"Date: "<<p[i]->getdate()<<endl;
        }
    }
    ~Passport()
    {
        for(int j; j<i ;j++)
        {
            delete p[j];
            
        }
        delete[] p;
    }
};

int main()
{
    

    Passport Talal;
    Talal.setcap(2);
    Talal.setname("Talal");

    Talal.setPlace("Hotel", "23/2/2025");
    Talal.setPlace("Stadium", "24/2/2025");

    Talal.display();
}