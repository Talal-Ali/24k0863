#include<iostream>
#include<math.h>
using namespace std;

static int sum = 0;
int reverseInt(int n)
{
    if(n == 0)
    {
        return sum/10;
    }
    int mod = n%10;
    sum+=mod;
    sum*=10;
    return reverseInt(n/10);
}

int powerTower(int n,int a)
{

    if(n==1)
    {
        return a;
    }
    if(n==0) return 1;
    return pow(a, powerTower(n-1, a));
}
int gcdfunction(int a, int b, int divisor, int gcd = 1)
{
    int large, small;
    if (a > b) { large = a; small = b; }
    else { small = a; large = b; }

    if (divisor > small) {
        return gcd;
    }

    if (large % divisor == 0 && small % divisor == 0) {
        gcd = divisor;
    }

    return gcdfunction(a, b, divisor + 1, gcd);
}


int main()
{
    cout<<reverseInt(12345)<<endl;
    cout<<powerTower(0,2)<<endl;;
    cout<<gcdfunction(15, 20, 1)<<endl;
}