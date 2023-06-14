// Sort an array of 0s,1s and 2s

// Brute Force Approach
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int arr[] = {0,1,2,0,1,2,1,2,0,0,0,1};
//     int n = sizeof(arr)/sizeof(arr[0]);


//     sort(arr,arr+n);

//     for(int ele : arr)
//     {
//         cout << ele << " ";
//     }
//     cout << endl;

//     // T.C => O(nlogn)
//     // S.C => O(1)
//     return 0;
// }

// Better Approach

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int arr[] = {0,1,2,0,1,2,1,2,0,0,0,1};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     int cnt_zero = 0;
//     int cnt_ones = 0;
//     int cnt_twos = 0;

//     for(int i = 0; i < n; ++i)
//     {
//         if(arr[i] == 0)
//         {
//             cnt_zero++;
//         }else if(arr[i] == 1)
//         {
//             cnt_ones++;
//         }else{
//             cnt_twos++;
//         }
//     }

//     for(int i = 0; i < cnt_zero; ++i)
//     {
//         arr[i] = 0;
//     }

//     for(int i = cnt_zero; i < cnt_zero+cnt_ones; ++i)
//     {
//         arr[i] = 1;
//     }

//     for(int i = cnt_zero+cnt_ones; i < n; ++i)
//     {
//         arr[i] = 2;
//     }

//     for(int ele : arr)
//     {
//         cout << ele << " ";
//     }

//     // T.C => O(N + N) => O(2N)
//     // S.C => O(1)
//     return 0;
// }


// Optimized Approach
#include<bits/stdc++.h>
using namespace std;
int main()
{
    // Using Dutch National flag Algorithm
    int arr[] = {0,1,2,0,1,2,1,2,0,0,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int low = 0;
    int mid = 0;
    int high = n - 1;

    for(int i = 0; i < n; ++i)
    {
        if(arr[mid] == 0)
        {
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }else if(arr[mid] == 1)
        {
            mid++;
        }else if(arr[mid] == 2)
        {
            swap(arr[mid],arr[high]);
            high--;
        }
    }

    // T.C => O(N)
    // S.C => O(1)
    
    for(int ele : arr)
    {
        cout << ele << " ";
    }

    return 0;
}