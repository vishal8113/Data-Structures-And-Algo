// search in rotated sorted array (only unique elements)
// arr[] = {7,8,9,1,2,3,4,5,6}
// target = 1

#include<bits/stdc++.h>
using namespace std;

int findIndex(int* arr,int n,int target)
{
    int start = 0;
    int end = n - 1;

    while(start <= end)
    {
        int mid = start + (end - start)/2;

        if(arr[mid] == target)
        {
            return mid;
        }

        // left half sorted
        if(arr[start] <= arr[mid])
        {
            if(arr[start] <= target && target <= arr[mid])
            {
                end = mid - 1;
            }else {
                start = mid + 1;
            }
        }else {  // right half sorted
            if(arr[mid] <= target && target <= arr[end])
            {
                start = mid + 1;
            }else {
                end = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    int arr[] = {7,8,9,1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    int target = 8;

    int ansIndex = findIndex(arr,n,target);

    cout << ansIndex << endl;

    // T.C => O(logn)
    // S.C => O(1)
    return 0;
}