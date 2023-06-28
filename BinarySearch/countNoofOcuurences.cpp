// count no. of occurences in an sorted array

#include<bits/stdc++.h>
using namespace std;

int First(int* arr,int n,int x)
{
    int start = 0;
    int end = n - 1;

    int ans = -1;

    while(start <= end)
    {
        int mid = start + (end - start)/2;

        if(arr[mid] == x)
        {
            ans = mid;
            end = mid - 1;
        }else if(arr[mid] < x)
        {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return ans;
}

int Second(int* arr,int n,int x)
{
    int start = 0;
    int end = n - 1;

    int ans = -1;

    while(start <= end)
    {
        int mid = start + (end - start)/2;

        if(arr[mid] == x)
        {
            ans = mid;
            start = mid + 1;
        }else if(arr[mid] < x)
        {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1,2,3,4,4,5,5,6,6,6,8,10};
    int n = sizeof(arr)/sizeof(arr[0]);

    int x = 6;

    int first = First(arr,n,x);
    int second = Second(arr,n,x);

    int ans = second - first + 1;

    cout << ans << endl;
    return 0;
}