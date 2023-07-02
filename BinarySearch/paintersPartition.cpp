// painter Partiton

// Brute Force
// #include<bits/stdc++.h>
// using namespace std;

// int maxi(int* arr,int n)
// {
//     int k = arr[0];
//     for(int i = 1; i < n; ++i)
//     {
//         if(arr[i] > k)
//         {
//             k = arr[i];
//         }
//     }

//     return k;
// }

// int fn(int* arr,int n,int time,int i)
// {
//     int paintersCnt = 1;
//     int sum = 0;
//     for(int j = 0; j < n; ++j)
//     {
//         sum += arr[j];
//         if(sum > i)
//         {
//             sum = arr[j];
//             paintersCnt++;
//         }
//     }

//     return paintersCnt;
// }

// int main()
// {
//     int arr[] = {1,8,11,3};
//     int n = 4;
//     int time = 1;
//     int painters = 10;

//     int ans = -1;

//     int maxEle = maxi(arr,n);
//     int sum = accumulate(arr,arr+n,0);

//     for(int i = maxEle; i <= sum; ++i)
//     {
//         int paintersCnt = fn(arr,n,1,i);
//         if(paintersCnt <= painters)
//         {
//             ans = i;
//             break;
//         }
//     }

//     cout << ans*time << endl;
//     return 0;
// }

// Optimal Approach

#include<bits/stdc++.h>
using namespace std;

int maxi(int* arr,int n)
{
    int k = arr[0];
    for(int i = 1; i < n; ++i)
    {
        if(arr[i] > k)
        {
            k = arr[i];
        }
    }

    return k;
}

int fn(int* arr,int n,int time,int i)
{
    int paintersCnt = 1;
    int sum = 0;
    for(int j = 0; j < n; ++j)
    {
        sum += arr[j];
        if(sum > i)
        {
            sum = arr[j];
            paintersCnt++;
        }
    }

    return paintersCnt;
}

int main()
{
    int arr[] = {1,8,11,3};
    int n = 4;
    int time = 1;
    int painters = 10;

    int maxEle = maxi(arr,n);
    int sum = accumulate(arr,arr+n,0);

    int start = maxEle;
    int end = sum;

    while(start <= end)
    {
        int mid = start + (end - start)/2;
        int paintersCnt = fn(arr,n,1,mid);
        if(paintersCnt <= painters)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    cout << start*time << endl;
    return 0;
}