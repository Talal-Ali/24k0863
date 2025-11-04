/*
🟢 Level 4: Constraints

Generate Valid Parentheses
Given n, generate all strings with n pairs of valid parentheses.
Example n=3: ["((()))","(()())","(())()","()(())","()()()"].

👉 Teaches: adding constraints (open <= n, close <= open).

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void paranthesis(vector<string>& result, int n, int open, int closed, string current)
{
    if(current.size() == n*2)
    {
        result.push_back(current);
        return;
    }   
    
    if(open< n)
    {
        paranthesis(result, n, open+1, closed, current + "(");
    }
    if(closed< open)
    {
        paranthesis(result, n, open, closed+1, current + ")");
    }
    
}

vector<string> valid(int n)
{
    vector<string> result;
    string current ="";
    paranthesis(result, n, 0, 0, current);
    return result;
}

int main()
{
    vector<string> result = valid(3);
    for (auto &vec : result)
    {
        cout << "";
        for (size_t i = 0; i < vec.size(); i++)
        {
            cout << vec[i];
            if (i + 1 < vec.size()) cout << " ";
        }
        cout << "" << endl;
    }
}