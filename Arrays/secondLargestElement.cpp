// Second largest element in an array

// Brute Force
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int arr[] = {2,45,11,7,11,45,8,11};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     // sort the array
//     sort(arr,arr+n); // n log n

//     int largest = arr[n-1];
//     int sl = -1;
//     for(int i = n - 2; n > 0; --i) // O(n)
//     {
//         if(arr[i] != largest)
//         {
//             sl = arr[i];
//             break;
//         }
//     }

//     // Total -> O(n log n) + O(n)

//     cout << sl << endl;
// }

// Optimized Approach
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int arr[] = {2,45,11,7,11,45,8,11};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     int largest = arr[0];  
//     for(int i = 1; i < n; ++i)  // O(n)
//     {
//         if(arr[i] > largest)
//         {
//             largest = arr[i];
//             break;
//         }
//     }

//     int sl = -1;
//     for(int i = 0; i < n; ++i)   // O(n)
//     {
//         if(arr[i] != largest && arr[i] > sl)
//         {
//             sl = arr[i];
//         }
//     }

//     // T.C => O(2N)

//     cout << sl << endl;

//     return 0;
// }

// More optimized approach
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2,45,11,7,11,45,8,11,32};
    int n = sizeof(arr)/sizeof(arr[0]);

    int largest = arr[0];
    int sl = -1;

    for(int i = 1; i < n; ++i)  // O(n)
    {
        if(arr[i] > largest)
        {
            sl = largest;
            largest = arr[i];
        }

        if(arr[i] > sl && arr[i] != largest)
        {
            sl = arr[i];
        }
    }

    cout << sl << endl;

    // T.C => O(n)

    return 0;
}