// arr[]= {5,3,2,4,1}

// i < j && arr[i] > arr[j]

// ans = 8(Count of pairs)

// Brute Force Approach

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {5,3,2,4,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int cnt = 0;
    for(int i = 0;i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(arr[i] > arr[j])
            {
                cnt++;
            }
        }
    }

    // T.C => O(n^2)
    // S.C => O(1)

    cout << cnt << endl;
    return 0;
}


// Optimal Approach

#include<bits/stdc++.h>
using namespace std;

// int cnt = 0;

int merge(int* arr,int low,int mid,int high)
{
    int cnt = 0;
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
            cnt += (mid - left + 1);
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

    return cnt;
}

int divide(int* arr,int low,int high)
{
    int cnt = 0;
    if(low >= high)
    {
        return cnt;
    }

    int mid = (low + high)/2;

    cnt += divide(arr,low,mid);
    cnt += divide(arr,mid+1,high);
    cnt += merge(arr,low,mid,high);

    return cnt;
}
int main()
{
    int arr[] = {5,3,2,4,1};

    int n = sizeof(arr)/sizeof(arr[0]);

    int cnt = divide(arr,0,n-1);

    cout << cnt << endl;

    // T.C => O(nlogn)
    // S.C => O(n)

    return 0;
}