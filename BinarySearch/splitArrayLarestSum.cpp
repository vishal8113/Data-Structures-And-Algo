// Split Array Largest Sum

// nums = [7,2,5,10,8], k = 2
// Output: 18

#include<bits/stdc++.h>
using namespace std;

int maxi(int* arr,int n)
{
    int k = arr[0];
    for(int i = 1; i < n; ++i)
    {
        if(k > arr[i])
        {
            k = arr[i];
        }
    }
    return k;
}

int getSubarrayCnt(int* arr,int n,int mid,int k)
{
    int sum = 0;
    int currSubarry = 1;
    for(int i = 0; i < n; ++i)
    {
        if(sum + arr[i] <= mid)
        {
            sum+=arr[i];
        }else{
            currSubarry++;
            sum=arr[i];
        }
    }

    return currSubarry;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    int k = 2;

    int maxEle = maxi(arr,n);
    int sum = accumulate(arr,arr+n,0);

    int start = maxEle;
    int end = sum;

    while(start <= end)
    {
        int mid = start + (end - start)/2;

        int subarrays = getSubarrayCnt(arr,n,mid,k);

        if(subarrays <= k)
        {
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }

    cout << start << endl;
    return 0;
}