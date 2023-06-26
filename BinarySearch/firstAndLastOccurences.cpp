// find the first ans last occurences of an x in sorted array
// ex :- {1,3,5,5,7,8,8,8,9,11,13}
// ans = {5,7}

#include<bits/stdc++.h>
using namespace std;

int First(vector<int> &v,int target)
{
    int n = v.size();

    int ans = -1;
    int start = 0;
    int end = n - 1;

    while(start <= end)
    {
        int mid = start + (end - start)/2;
        if(v[mid] == target)
        {
            ans = mid;
            end = mid - 1;
        }else if(v[mid] < target)
        {
            start = mid + 1;
        }else {
            end = mid - 1;
        }
    }

    return ans;
}

int Second(vector<int> &v,int target)
{
    int n = v.size();

    int ans = -1;
    int start = 0;
    int end = n - 1;

    while(start <= end)
    {
        int mid = start + (end - start)/2;
        if(v[mid] == target)
        {
            ans = mid;
            start = mid + 1;
        }else if(v[mid] < target){
            start = mid + 1;
        }else {
            end = mid - 1;
        }
    }

    return ans;
}
int main()
{
    vector<int> v = {1,3,5,5,7,8,8,8,9,11,13};
    int n = v.size();
    int target = 11;

    pair<int,int> p;

    // int first = lower_bound(v.begin(),v.end(),target) - v.begin();
    // int second = upper_bound(v.begin(),v.end(),target) - v.begin() - 1;

    // if(first < n && v[first] == target)
    // {
    //     p = {first,second};
    // }else {
    //     p = {-1,-1};
    // }

    int first = First(v,target);
    int second = Second(v,target);

    p = {first,second};

    cout << p.first << " , " << p.second << endl;
    return 0;
}