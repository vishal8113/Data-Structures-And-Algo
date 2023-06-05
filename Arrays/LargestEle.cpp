// Largest element in an array

// Brute Force
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int arr[] = {5,8,12,34,7};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     // sort the array
//     sort(arr,arr+n); // (nlogn)

//     cout << arr[n - 1];
// }

// Optimal
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {5,8,12,34,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    int largest = arr[0];
    for(int i = 1; i < n; ++i)
    {
        if(largest < arr[i])
        {
            largest = arr[i];
        }
    }

    // Time Complexity -> O(n)

    cout << largest << endl;
}