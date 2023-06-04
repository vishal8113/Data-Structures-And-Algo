// Given an array a of n integers. Given q queries
// and in each query we have given a number y,print 
// frequency of y in an array

// Constraints
// 1 <= N <= 10^5
// 1 <= a[i] <= 10^7
// 1 <= 10^5 <= 10^5

#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
int main()
{
    int hash[N];
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        hash[arr[i]]++;

    }
    

    int q;
    cin >> q;
    while(q--)
    {
        int y;
        cin >> y;
        // int cnt = 0;
        // for(int i = 0; i < n; ++i)
        // {
        //     if(arr[i] == y)
        //     {
        //         cnt++;
        //     }
        // }
        // cout << cnt << endl;
        cout << hash[y] << endl;
    }

    return 0;
}
