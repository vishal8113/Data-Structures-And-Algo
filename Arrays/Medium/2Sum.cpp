// 2 Sum Problem
// arr = {2,6,5,8,11} , target = 14
// ans = 6 and 8


// Brute Force
// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int arr[] = {2, 6, 5, 8, 11};
//     int n = 5;
//     int target = 14;
//     bool foundPair = false;

//     vector<int> ans;
//     for (int i = 0; i < n; ++i)
//     {
//         for (int j = 0; j < n; ++j)
//         {
//             if (arr[i] + arr[j] == target)
//             {
//                 ans.push_back(arr[i]);
//                 ans.push_back(arr[j]);
//                 foundPair = true;
//                 break;
//             }
//         }

//         if(foundPair)
//         {
//             break;
//         }
//     }

//     for (int el : ans)
//     {
//         cout << el << " ";
//     }

//     // T.C => O(n^n);
//     // S.C => O(1)
    
//     return 0;
// }


// Optimized Approach
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2, 6, 5, 8, 11};
    int n = 5;
    int target = 14;
    bool pairFind = false;

    map<int,int> m;

    for(int i = 0; i < n; ++i)  // O(n)
    {
        int num = arr[i];
        int moreNeeded = target - num;

        if(m.find(moreNeeded) != m.end()) // (logn)
        {
            cout << moreNeeded << " " << arr[i];
            break;
        }

        m[num] = i;
    }


    // T.C => O(NlogN)
    // S.C => O(n)
    return 0;
}
