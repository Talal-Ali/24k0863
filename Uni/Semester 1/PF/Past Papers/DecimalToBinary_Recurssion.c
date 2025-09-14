#include<stdio.h>

int DecToBin(int dec,int n)
{
    //int n =1;
    if(dec == 0)
    {
        return 0;
    }
    int bin = (dec%2)*n;
    n *=10;
    return (bin+DecToBin(dec/2,n));
}

int main()
{
    
    printf("%d", DecToBin(127,1));
}