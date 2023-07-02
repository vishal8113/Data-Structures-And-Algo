// Eko (SPOJ PROBLEM)

// Brute Force
// #include <bits/stdc++.h>
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

// int mini(int* arr,int n){
//     int k = arr[0];
//     for(int i = 1; i < n; ++i)
//     {
//         if(arr[i] < k)
//         {
//             k = arr[i];
//         }
//     }
//     return k;
// }

// bool canPossible(int* arr,int n,int height,int m)
// {
//     int sum = 0;
//     for (int i = 0; i < n; ++i)
//     {
//         if (arr[i] > height)
//         {
//             sum += (arr[i] - height);
//         }
//     }

//     return sum >= m;
// }

// int main()
// {
//     int arr[] = {4,42,40,26,46};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     int m = 20;
//     int ans = -1;

//     int maxEle = maxi(arr, n);
//     int minEle = mini(arr, n);

//     for (int i = minEle; i <= maxEle; ++i)
//     {
//         if (canPossible(arr,n,i,m) == true)
//         {
//             ans = i;
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }


// Optimal Solution

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed maxi(int* arr,int n)
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

signed mini(int* arr,int n){
    int k = arr[0];
    for(int i = 1; i < n; ++i)
    {
        if(arr[i] < k)
        {
            k = arr[i];
        }
    }
    return k;
}

bool canPossible(int* arr,int n,int height,int m)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] > height)
        {
            sum += (arr[i] - height);
        }
    }

    return sum >= m;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;
    int arr[n];

    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int maxEle = maxi(arr, n);
    int minEle = mini(arr, n);

    int start = minEle;
    int end = maxEle;

    while(start <= end)
    {
        int mid = start + (end - start)/2;

        if(canPossible(arr,n,mid,m) == true){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }

    cout << end << endl;

    return 0;
}

