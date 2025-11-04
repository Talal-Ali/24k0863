/*
All Subsets (Power Set)
Given nums = [1,2,3], return all subsets.
Example: [[], [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3]].

👉 Teaches: at each step, take or skip the element.
*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> powerSet(vector<int>& subset, int n, vector<vector<int>>& result, int pos, vector<int> &nums)
{
    
    if(pos == n)
    {
        result.push_back(subset);
        return result;
    }
    
    powerSet(subset, n, result, pos+1, nums);
    subset.push_back(nums[pos]);
    powerSet(subset, n, result, pos+1, nums);
    subset.pop_back();
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    int n = nums.size();

    vector<int> subset;             
    vector<vector<int>> result;     

    result = powerSet(subset, n, result, 0, nums);

    for (auto &vec : result) {
        cout << "{";
        for (auto &x : vec) cout << x << "";
        cout << "}" << endl;
    }

    return 0;
}