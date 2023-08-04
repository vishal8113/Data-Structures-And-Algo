// find all permutations of array (1st)

class Solution {
public:
void recPermutation(vector<int> &ds,vector<int> &nums,vector<vector<int>> &ans,int freq[]){
    if(ds.size() == nums.size()){
        ans.push_back(ds);
        return;
    }

    for(int i = 0; i < nums.size(); ++i)
    {
        if(!freq[i]){
            ds.push_back(nums[i]);
            freq[i] = 1;
            recPermutation(ds,nums,ans,freq);
            ds.pop_back();
            freq[i] = 0;
        }
    }
}
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        for(int i = 0;i < nums.size(); ++i)
        {
            freq[i] = 0;
        }
        recPermutation(ds,nums,ans,freq);

        return ans;

        // T.C => O(n! * n)
        // S.C => O(n) + O(n)
    }
};

// find all permutations of array (2nd approach)

class Solution {
public:
void recPer(int ind,vector<int> &nums,vector<vector<int>> &ans)
{
    if(ind == nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int i = ind; i < nums.size(); ++i)
    {
        swap(nums[ind],nums[i]);
        recPer(ind + 1,nums,ans);
        swap(nums[ind],nums[i]);
    }
}
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recPer(0,nums,ans);
        return ans;
    }
};