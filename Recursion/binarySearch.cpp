// Binary Search using recursion

#include<bits/stdc++.h>
using namespace std;

int bs(int* arr,int start,int end,int target)
{
    if(start > end)
    {
        return -1;
    }

    int mid = start + (end - start)/2;
    if(arr[mid] == target)
    {
        return mid;
    }else if(arr[mid] < target)
    {
        return bs(arr,mid+1,end,target);
    }

    return bs(arr,start,end-1,target);
}

int main()
{
    int arr[] = {1,3,5,8,10,12,13,23,45,90};
    int n = sizeof(arr)/sizeof(arr[0]);

    int start = 0;
    int end = n - 1;
    int target = 12;

    int ans = bs(arr,start,end,target);

    cout << ans << endl;
    return 0;
}
