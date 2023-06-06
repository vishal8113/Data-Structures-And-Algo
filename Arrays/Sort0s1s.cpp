// Sort the array of 0s and 1s
// Ex:- {1,0,1,1,0,1,1,0,1,1} -> {0,0,0,1,1,1,1,1,1,1}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {0,1,1,1,1,0,1,0,1,0,0,1,0,0,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    // Brute Force
    // Sort the array
    // sort(arr,arr+n);  T.C => (nlogn)


    // Optimized Approach
    // int count = 0;
    // for(int i = 0; i < n; ++i)  // O(n)
    // {
    //     if(arr[i] == 0){
    //         count++;
    //     }
    // }

    
    // for(int i = 0; i < count; ++i)  // (c)
    // {
    //     arr[i] = 0;
    // }

    // for(int i = count;i < n; ++i)   // O(n-c)
    // {
    //     arr[i] = 1;
    // }

    // T.C = O(n) + O(c) + O(n-c) => O(2N)

    int start = 0;
    int end = n - 1;
    while(start < end)  // T.C => O(n)
    {
        while(arr[start] == 0 && start < end)
        {
            start++;
        }

        while(arr[end] == 1 && start < end)
        {
            end--;
        }

        if(arr[start] == 1 && arr[end] == 0 && start < end)
        {
            swap(arr[start],arr[end]);
            start++;
            end--;
        }
        
    }

    for(int ele : arr)
    {
        cout << ele << " ";
    }
    
    return 0;
}