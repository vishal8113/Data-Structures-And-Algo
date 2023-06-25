// arr[] = {40,25,19,12,9,6,2}
// i < j && arr[i] > 2 * arr[j]

// ans = 15

Brute Force
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {40,25,19,12,9,6,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    int cnt = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(arr[i] > 2 * arr[j])
            {
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}

// Optimal Approach

#include<bits/stdc++.h>
using namespace std;

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

int countPairs(int* arr,int low,int mid,int high)
{
    int cnt = 0;
    int right = mid + 1;
    for(int i = low; i <= mid; ++i)
    {
        while(right <= high && arr[i] > 2 * arr[right])
        {
            right++;
        }
        cnt += (right - (mid + 1));
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
    cnt += countPairs(arr,low,mid,high);
    cnt += merge(arr,low,mid,high);

    return cnt;
}

int main()
{
    int arr[] = {40,25,19,12,9,6,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    int cnt = divide(arr,0,n-1);

    cout << cnt << endl;
    return 0;
}
