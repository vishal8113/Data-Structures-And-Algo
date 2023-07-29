// Subset generation

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void generate(vector<int> &subset,int i,vector<int> &nums)
{
    if(i == nums.size())
    {
        ans.push_back(subset);
        return;
    }
    // ith element not consider(not subset)
    generate(subset,i+1,nums);

    // we consider ith element(subset)
    subset.push_back(nums[i]);
    generate(subset,i+1,nums);
    subset.pop_back();
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    vector<int> subset;
    generate(subset,0,nums);
    for(auto ele : ans)
    {
        for(auto i : ele)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    // T.C => O(2^n)
}
