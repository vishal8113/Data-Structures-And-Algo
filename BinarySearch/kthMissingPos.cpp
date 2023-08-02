//  find kth missing positive numbers

// arr[] = {2,3,4,7,11} , k = 5
// ans = 9

// Brute Force

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int arr[] = {2,3,4,7,11};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     int k = 5;

//     for(int i = 0; i < n; ++i)
//     {
//         if(arr[i] <= k)
//         {
//             k++;
//         }else {
//             break;
//         }
//     }

//     cout << k << endl;

//     // T.C => O(n)
//     // S.C => O(1)
//     return 0;
// }

// Optimal Solution

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2,3,4,7,11};
    int n = sizeof(arr)/sizeof(arr[0]);

    int k = 5;

    int start = 0;
    int end = n - 1;

    while(start <= end)
    {
        int mid = start + (end - start)/2;

        int missing = arr[mid] - (mid + 1);

        if(missing < k)
        {
            start = mid + 1;
        }else {
            end = mid - 1;
        }
    }

    // cout << end + 1 + k;
    cout << start + k << endl;

    // T.C => O(logn)
    // S.C => O(1)
    return 0;
}
