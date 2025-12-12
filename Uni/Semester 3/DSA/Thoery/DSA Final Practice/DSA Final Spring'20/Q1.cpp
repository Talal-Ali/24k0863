#include<iostream>
using namespace std;

class trans{
    string timestamp;
    string cardn;
    int amount;
    int c500;
    int c1000;
    int c5000;
    public:
        trans():timestamp("00:00:00"), cardn("000000"), amount(0), c500(0), c1000(0), c5000(0){}
        trans(string c):timestamp("00:00:00"), cardn(c), amount(0), c500(0), c1000(0), c5000(0){}
        void increasec500(int n){
            c500 += n;amount += n;
        }
        void increasec1000(int n){
            c1000 += n;amount += n;
        }
        void increasec5000(int n){
            c5000 += n;amount += n;
        }
};

class dma{
    trans *t;
    int size;
    public:
        dma(){
            size = 1;
            t = new trans[size];
        }
        dma(int s)
        {
            size = s;
            t = new trans[size];
        }
        ~dma()
        {
            delete [] t;
        }
        dma(dma &other)
        {
            size = other.size;
            t = new trans[size];
            for(int i = 0;i<size;i++)
            {
                t[i] = other.t[i];
            }
        }
        dma& operator=(dma& other)
        {
            if(this != &other)
            {
                delete []t;
                size = other.size;
                t = new trans[size];
                for(int i = 0; i<size; i++)
                {
                    t[i] = other.t[i];
                }
            }
            return *this;
        }
};
