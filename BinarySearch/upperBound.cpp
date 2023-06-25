// Implement Upper Bound
// smallest index such that arr[ind] > x

#include<bits/stdc++.h>
using namespace std;

int ub(int* arr,int n,int x)
{
    int start = 0;
    int end = n - 1;

    int ans = n;

    while(start <= end)
    {
        int mid = start + (end - start)/2;
        if(arr[mid] > x)
        {
            ans = mid;
            end = mid - 1;
        }else {
            start = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int arr[] = {2,3,6,7,8,8,11,11,12};
    int n = sizeof(arr)/sizeof(arr[0]);

    int x = 6;

    // int it = upper_bound(arr,arr+n,x) - arr;

    // cout << it << endl;

    int ans = ub(arr,n,x);

    cout << ans << endl;
    return 0;
}