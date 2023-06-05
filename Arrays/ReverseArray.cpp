// Reverse the array

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2,56,12,89,45,11,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Reversing using two pointers approach
    int start = 0;
    int end = n - 1;

    while(start <= end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }

    for(int ele : arr)
    {
        cout << ele << endl;
    }

    return 0;
}