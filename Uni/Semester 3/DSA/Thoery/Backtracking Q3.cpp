/*
Combinations
Choose k numbers from 1..n.
Example: n=4, k=2 → [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]].

👉 Teaches: controlling recursion depth.

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> combinations(vector<int>& set, vector<int>& subset, vector<vector<int>>& result, int n, int pos, int k)
{
    if (pos == n) {
        if (subset.size() == k)
            result.push_back(subset);
        return result;
    }
    if(subset.size()==k)
    {
        result.push_back(subset);
        return result;
    }

    combinations(set, subset, result, n, pos+1, k);
    subset.push_back(set[pos]);
    combinations(set, subset, result, n, pos+1, k);
    subset.pop_back();
    return result;
}

int main()
{
    vector<int> set = {1, 2, 3};
    int n = set.size();
    int k = 2;

    vector<int> subset;        
    vector<vector<int>> result;

    result = combinations(set, subset, result, n, 0, k);

    cout << "Combinations of size " << k << ":" << endl;
    for (auto &vec : result)
    {
        cout << "{";
        for (size_t i = 0; i < vec.size(); i++)
        {
            cout << vec[i];
            if (i + 1 < vec.size()) cout << ",";
        }
        cout << "}" << endl;
    }

    return 0;
}