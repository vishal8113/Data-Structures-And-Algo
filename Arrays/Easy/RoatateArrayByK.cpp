// Rotate Array by k places, where k be an any number
// Ex: {23,45,12,89,25}, k = 7
// 1st Rotation -> {45,12,89,25,23}
// 2nd Rotation -> {12,89,25,23,45}
// 3rd Rotation -> {89,25,23,45,12}
// 4th Rotation -> {25,23,45,12,89}
// 5th Rotation -> {23,45,12,89,25} // get original array
// 6th rotation -> n + 1
// 7th rotation -> n + 2, k = k % n

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {45,12,89,25,23};
    int n = sizeof(arr)/sizeof(arr[0]);

    int k = 2;
    // cin >> k;
    k = k % n;

    // int temp[k];
    // for(int i = 0; i < k; ++i)  // O(k)
    // {
    //     temp[i] = arr[i];
    // }

    // for(int i = k; i < n; ++i)  // O(n-k)
    // {
    //     arr[i-k] = arr[i];
    // }
   
    //  // int j = 0;
    // for(int i = n - k; i < n; ++i)  // O(k)
    // {
    //     // arr[i] = temp[j++];
    //     arr[i] = temp[i-(n-k)];
    //     // j++;
    // }

    // T.C => O(k) + O(n-k) + O(k)
    // S.C => O(k) (temp array)

    // Approach that make space complexity constant
    reverse(arr,arr+k);  // O(k)
    reverse(arr+k,arr+n);  // O(n-k)
    reverse(arr,arr+n);  // O(n)

    // T.C => O(k) + O(n-k) + O(n)
    // S.C => O(1)

    for(int ele : arr)
    {
        cout << ele << " ";
    }

    return 0;
}
