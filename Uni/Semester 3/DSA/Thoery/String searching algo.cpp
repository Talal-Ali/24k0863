#include <iostream>
using namespace std;

bool naiveSearch(const string& source, const string& search)
{
    int n = source.length();
    int m = search.length();

    for(int i= 0; i<= n-m; i++)
    {
        int j = 0;
        while(j<m && source[i+j] == search[j])
        {
            if(j==m) return true;
        }
    }
    return false;
}

int kmp(const string& source, const string& search)
{
    int n = source.length();
    int m = search.length();

    int* lps = new int[m];
    lps[0] = 0;
    int len = 0;

    for(int i=1; i<m;)
    {
        if(search[i] ==  search[len])
        {
            lps[i++] = ++len;
        }
        else if(len)
        {
            len = lps[len-1];
        }
        else{
            lps[i++] = 0;
        }
    }
    for(int i=0, j = 0; i<n;)
    {
        if(source[i] == search[j])
        {
            i++;j++;
        }
        if(j == m)
        {
            delete [] lps;
            return i-j;
        }
        if(i<n && source[i] != search[j])
        {
            if(j)
            {
                j = lps[j -1];
            }
            else{i++;}
        }
    }
    delete [] lps;
    return -1;
}

int BM(const string& source, const string& search) {
    int bad[256];
    for (int i = 0; i < 256; i++) bad[i] = -1;

    for (int i = 0; i < (int)search.length(); i++)
        bad[(unsigned char)search[i]] = i;

    int n = source.length();
    int m = search.length();
    int shift = 0;

    while (shift <= n - m) {
        int j = m - 1;
        while (j >= 0 && search[j] == source[shift + j]) j--;
        if (j < 0) return shift;

        int skip = j - bad[(unsigned char)source[shift + j]];
        if (skip < 1) skip = 1;
        shift += skip;
    }
    return -1;
}

int Rabin(const string& source, const string& search) {
    int n = source.length();
    int m = search.length();

    int d = 256;
    int q = 101;
    int h = 1, p = 0, t = 0;

    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (int i = 0; i < m; i++) {
        p = (d * p + search[i]) % q;
        t = (d * t + source[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            int j = 0;
            while (j < m && search[j] == source[i + j]) j++;
            if (j == m) return i;
        }
        if (i < n - m) {
            t = (d * (t - source[i] * h) + source[i + m]) % q;
            if (t < 0) t += q;
        }
    }

    return -1;
}