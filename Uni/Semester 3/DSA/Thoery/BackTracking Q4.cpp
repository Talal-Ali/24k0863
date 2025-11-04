/*
🟢 Level 3: Ordering

Permutations
Given nums=[1,2,3], return all permutations.
Example: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]].

👉 Teaches: marking elements as used, exploring all orderings.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> permutations(vector<int> &subset, vector<int> &set, vector<vector<int>> &result, int n)
{
    
    if(subset.size() == set.size())
    {
        result.push_back(subset);
        return result;
    }
    //permutations(subset, set, result, pos+1, n);
    for(int i =0; i<n; i++)
    {
        if(find(subset.begin(), subset.end(), set[i]) == subset.end())
        {
            subset.push_back(set[i]);
            permutations(subset, set, result, n);
            subset.pop_back();
        }
        
    }
    
    return result;

}

int main()
{
    vector<int> set = {1, 2, 3};
    int n = set.size();
    vector<int> subset;        
    vector<vector<int>> result;

    result = permutations(subset, set, result, n);

    cout << "Permutations:" << endl;
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
