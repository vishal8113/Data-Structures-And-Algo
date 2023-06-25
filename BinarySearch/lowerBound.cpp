// Implement lower bound
// smallest index such that arr[index] >= x

#include<bits/stdc++.h>
using namespace std;

int lb(int* arr,int n,int x)
{
    int start = 0;
    int end = n - 1;

    int ans = n;
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        if(arr[mid] >= x)
        {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int arr[] = {1,2,3,3,7,8,8,9,9,11};
    int n = sizeof(arr)/sizeof(arr[0]);

    int x = 2;

    int ans = lb(arr,n,x);

    cout << ans << endl;

    // auto it = lower_bound(arr,arr+n,x) - arr;
    // cout << it << endl;
    return 0;
}