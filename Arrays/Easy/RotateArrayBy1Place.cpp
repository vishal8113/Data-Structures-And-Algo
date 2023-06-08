// Rotate Array By 1 Place
// Ex: {12,45,11,90,56}; -> {45,11,90,56,12}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {12,45,11,90,56};
    int n = sizeof(arr)/sizeof(arr[0]);

    int temp = arr[0];
    for(int i = 1; i < n; ++i)  // O(n)
    {
        arr[i-1] = arr[i];
    }

    arr[n-1] = temp;

    for(int ele : arr)
    {
        cout << ele << " ";
    }

    return 0;
}