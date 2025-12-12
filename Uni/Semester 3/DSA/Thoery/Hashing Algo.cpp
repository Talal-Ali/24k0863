#include<iostream>
using namespace std;
//Data class is for demonstration
class Data{
public:
    int id;
    string name;
    int val;//will be used for hashing
    Data(){
        id = 0;
        name = "";
        val = 0;
    };
    Data(Data& d1)
    {
        id = d1.id;
        name = d1.name;
        val = d1.val;
    }
    bool operator==(Data &other)
    {
        if(other.id == id)
        {
            return true;
        }
        return false;
    }
    Data& operator=( Data& other)
    {
        id = other.id;
        name = other.name;
        val = other.val;

        return *this;
    }
};

class Entry
{
public:
    Data d;
    bool used;
    bool deleted;
    Entry* next;
    Entry():used(false), deleted(false),next(nullptr){}
    Entry(Data d1):d(d1), used(false), deleted(false), next(nullptr){}
    void output(){
        cout<<"ID: "<<d.id<<" Name: "<<d.name<<" Val: "<<d.val;
    }
};
class LinearHashing{
    Entry *e;
    int size;
    public:
        LinearHashing() 
        {
            size = 10;
            e = new Entry[size];
        }
        LinearHashing(int s)
        {
            size = s;
            e = new Entry[size];
        }
        int hashf(int v)
        {
            return ((v+5) %size);
        }
        void add(Entry e1)
        {
            for(int i=0;i<size; i++)
            {
                int idx = (hashf(e1.d.val) + i)% size;
                if(!e[idx].used || e[idx].deleted)
                {
                    e[idx].d = e1.d;
                    e[idx].used = true;
                    e[idx].deleted = false;
                    return;
                }
            }

        }
        int find(Data key)
        {
            for(int i = 0; i < size; i++)
            {
                int idx = (hashf(key.val) + i) % size;

                if(!e[idx].used && !e[idx].deleted)
                    return -1;  

                if(e[idx].used && e[idx].d == key)
                    return idx;
            }
            return -1;
        }

        void remove(Data key)
        {
            for(int i = 0; i < size; i++)
            {
                int idx = (hashf(key.val) + i) % size;

                if(e[idx].used && e[idx].d == key)
                {
                    e[idx].used = false;
                    e[idx].deleted = true;
                    return;
                }
            }
        }

        void print()
        {
            cout<<"====================Linear Probing===================="<<endl;
            for(int i = 0; i<size; i++)
            {
                if(e[i].used)
                {
                    cout<<"Index = "<< i<<" ";
                    e[i].output();
                    cout<<endl;
                }
                
            }
        }

};
class seperatechaining{
    Entry *e;
    int size;
    public:
        seperatechaining()
        {
            size = 10;
            e = new Entry[size];
        }
        seperatechaining(int s)
        {
            size = s;
            e = new Entry[size];
        }
        int hashf(int v)
        {
            return ((v+5)/2);
        }
        void add(Data d )
        {
            
            int idx = hashf(d.val) % size;
            if(!e[idx].used || e[idx].deleted)
            {
                e[idx].d = d;
                e[idx].used = true;
                e[idx].deleted = false;
                return;
            }
            if(e[idx].used)
            {
                Entry *temp = &e[idx];
                while(temp->next)
                {
                    temp = temp->next;
                }
                temp->next = new Entry(d);
                temp->next->used = true;
                temp->next->deleted = false;
                return;
            }
        }
        int find(Data d)
        {
            int idx = hashf(d.val) %size;
            if(!e[idx].used && !e[idx].deleted)
            {
                return -1;
            }
            Entry* temp = &e[idx];
            int count = 0;
            while(temp)
            {
                if(!(temp->d == d))
                {
                    temp = temp->next;
                    count++;
                }
                else
                {
                    cout<<"\nFound at idx: "<<idx<<" At chain: "<<count<<endl;
                    return idx;
                }
                
            }
            
        }
        void remove(Data d)
        {
            int idx = hashf(d.val) %size;
            Entry* head = &e[idx];
            Entry* temp = head;
            Entry* prev = nullptr;

            while (temp) {
                if (temp->d == d) {
                    if (prev == nullptr) {
                        Entry* firstReal = temp->next;
                        if (firstReal) {
                            temp->d = firstReal->d;
                            temp->next = firstReal->next;
                            delete firstReal;
                        } else {
                            temp->used = false;
                            temp->deleted = true;
                        }
                    } else {
                        prev->next = temp->next;
                        delete temp;
                    }
                    return;
                }
                prev = temp;
                temp = temp->next;
            }

        }
        void print()
        {
            cout<<"--------------Seperate chaining--------------"<<endl;
            for(int i = 0; i<size; i++)
            {
                int idx = hashf(e[i].d.val) %size;
                if(!e[idx].used || e[idx].deleted)
                {
                    continue;
                }
                Entry* head = &e[i];
                while(head)
                {
                    head->output();
                    cout<<"->";
                    head = head->next;
                }
                cout<<endl;
            }
            cout<<endl;
        }
};


int main()
{
    seperatechaining l(25);
    Data d1;
    d1.id = 101121;
    d1.name = "Ahmed";
    d1.val = 1044;

    Data d2;
    d2.id = 237123;
    d2.name = "Bilal";
    d2.val = 3471;

    Data d3;
    d3.id = 3354324;
    d3.name = "Sarah";
    d3.val = 1044;

    Data d4;
    d4.id = 248482;
    d4.name = "Zain";
    d4.val = 1813;

    Entry e(d1);
    Entry e2(d2);
    Entry e3(d3);
    Entry e4(d4);

    l.add(d1);
    l.add(d2);
    l.add(d3);
    l.add(d4);
    l.print();
    l.remove(d1);
    l.print();

}