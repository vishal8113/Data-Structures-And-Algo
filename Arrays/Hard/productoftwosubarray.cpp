// Maximum Product Subarray

// arr = [2,3,-2,4]
// ans = 6

// Brute Force

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2,3,-2,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    int maxi = INT_MIN;

    for(int i = 0; i < n; ++i)  // O(n)
    {
        int prod = 1;
        for(int j = i; j < n; ++j)  // O(n)
        {
            prod = prod * arr[j];

            maxi = max(maxi,prod);
        }
    }

    // T.C => O(n*n)
    // S.C => O(1)

    cout << maxi << endl;
    return 0;
}


// Optimal Approach

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2,3,-2,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    int prefix = 1;
    int suffix = 1;

    int maxi = INT_MIN;

    for(int i = 0; i < n; ++i)  // O(n)
    {
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;
        prefix = prefix * arr[i];
        suffix = suffix * arr[n-i-1];
        maxi = max(maxi,max(prefix,suffix));
    }

    // T.C => O(N)
    // S.C => O(1)

    cout << maxi << endl;
    return 0;
}