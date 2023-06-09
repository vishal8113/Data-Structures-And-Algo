#include<bits/stdc++.h>
using namespace std;
int main(){

    vector<int> nums = {4,3,2,7,8,2,3,1};
    int n = nums.size();


        int i = 0;

        while(i < n)
        {
            int ci = nums[i] - 1;

            if(i != ci && nums[ci] != ci+1)
            {
                swap(nums[i],nums[ci]);
            }else{
                i++;
            }
        }

        for(int k : v)
        {
            cout << k << " ";
        }
    return 0;
}