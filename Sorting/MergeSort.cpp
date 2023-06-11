// Merge Sort 
// T.C => O(nlogn)
// S.C => O(n)
// Based on Divide and merge 

#include<bits/stdc++.h>
using namespace std;

void merge(int* arr,int low,int mid,int high)
{
    vector<int> temp;

    int left = low;
    int right = mid + 1;

    while(left <= mid && right <= high)
    {
        if(arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i <= high; ++i)
    {
        arr[i] = temp[i - low];
    }
}

void divide(int* arr,int low,int high)
{
    if(low >= high)
    {
        return;
    }

    int mid = (low + high)/2;

    divide(arr,low,mid);
    divide(arr,mid+1,high);
    merge(arr,low,mid,high);
}

int main()
{
    int arr[] = {5,1,3,1,6,8,4,11,9,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int low = 0;
    int high = n - 1;

    divide(arr,low,high);

    for(int ele : arr)
    {
        cout << ele << " ";
    }

    return 0;
}