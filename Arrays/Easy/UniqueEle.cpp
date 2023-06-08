// Find the number that appear once
// arr = {1,1,3,3,4,5,5}
// ans = 4

// Brute Force Solution
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int arr[] = {1,1,3,3,4,5,5};
//     int n = sizeof(arr)/sizeof(arr[0]);
    
//     for(int i = 0; i < n; ++i)  // O(n)
//     {
//         int num = arr[i];
//         int cnt = 0;
//         for(int j = 0; j < n; ++j)  // O(n)
//         {
//             if(arr[j] == num)
//             {
//                 cnt++;
//             }
//         }

//         if(cnt == 1)
//         {
//             cout << num << endl;
//             break;
//         }
//     }

//     // T.C => O(n*n) => O(n^2)
//     // S.C => O(1)

//     return 0;
// }

// Optimized Solution
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1,1,3,3,4,5,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    unordered_map<int,int> m;

    // int maxi = 0;
    // for(int i = 0; i < n; ++i)  // O(n)
    // {
    //     maxi = max(maxi,arr[i]);
    // }

    // int hsh[maxi + 1] = {0};

    for(int i = 0; i < n; ++i)  //O(n) => n(logn)
    {
        // m[arr[i]]++; // log n
         m[arr[i]]++; // O(1)
    }
   
    // for(int i = 0; i <= maxi; ++i) // O(n)
    // {
    //     if(hsh[i] == 1)
    //     {
    //         cout << i << endl;
    //         break;
    //     }
    // }

    for(auto it : m)  // o(m)
    {
        if(it.second == 1){
            cout << it.first << endl;
        }
        // cout << it.first << " " << it.second << endl;
    }

    // T.C => O(3N) => O(N)
    // S.C => O(maxi)

    // T.C(hash map) => On(logn) + O(m) (ordered map)
    // S.C => O(m)

    // T.C => O(n) + O(m) => (2N) (In worst case)
    // S.C => O(m)

    return 0;
}

// More optimized Approach
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int arr[] = {1,1,3,3,4,5,5};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     int ans = 0;
//     for(int i = 0; i < n; ++i)  // O(n)
//     {
//         ans^=arr[i];
//     }

//     // T.C => O(n)
//     // S.C => O(1)

//     cout << ans << endl;
//     return 0;
// }