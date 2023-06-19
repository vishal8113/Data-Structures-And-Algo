// Maximum SubArray Sum
// Ex:- -2,-2,4,-1,-2,1,5,-3
// ans = 7


// // Brute Force
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int arr[] = {-2,-3,4,-1,-2,1,5,-3};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     int maxi = INT_MIN;

//     for(int i = 0; i < n; ++i)  // O(n)
//     {
//         int sum = 0;
//         for(int j = i; j < n; ++j) // O(n)
//         {
//             sum += arr[j];
//             maxi = max(maxi,sum);
//         }
//     }

//     // T.C => O(n^2)
//     // S.C => O(1)

//     cout << maxi << endl;
//     return 0;
// }


// Optimal Approach

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {-2,-3,4,-1,-2,1,5,-3};
    int n = sizeof(arr)/sizeof(arr[0]);

    int sum = 0;
    int maxi = INT_MIN;
    int start = -1;
    int ansStart = -1;
    int ansEnd = -1;
    for(int i = 0; i < n; ++i)  // O(n)
    {
        // if(sum == 0)
        // {
        //     start = i; // For Printing SubArray
        // }
        sum+=arr[i];

        if(sum > maxi)
        {
            maxi = sum;
            // ansStart = start;
            // ansEnd = i;
        }

        if(sum < 0)
        {
            sum = 0;
        }
    }

    // for(int i = ansStart; i <= ansEnd; ++i)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // T.C => O(n)
    // S.C => O(1)
    cout << maxi << endl;

    return 0;
}