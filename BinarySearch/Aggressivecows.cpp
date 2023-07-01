// Aggressive cows

// Brute Force
// #include<bits/stdc++.h>
// using namespace std;

// int maxi(int* arr,int n)
// {
//     int maxEle = arr[0];
//     for(int i = 0; i < n; ++i)
//     {
//         if(arr[i] > maxEle)
//         {
//             maxEle = arr[i];
//         }
//     }

//     return maxEle;
// }

// int mini(int* arr,int n)
// {
//     int minEle = arr[0];
//     for(int i = 0; i < n; ++i)
//     {
//         if(arr[i] < minEle)
//         {
//             minEle = arr[i];
//         }
//     }

//     return minEle;
// }

// bool canWePlace(int* arr,int n,int dist,int cows)
// {
//     int cnt_cows = 1;
//     int last = arr[0];

//     for(int i = 1; i < n; ++i)
//     {
//         if(arr[i] - last >= dist)
//         {
//             cnt_cows++;
//             last = arr[i];
//         }

//         if(cnt_cows >= cows)
//         {
//             return true;
//         }
//     }

//     return false;
// }

// int main()
// {
//     int arr[] = {0,3,4,7,10,9};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     int ans = -1;
//     int cows = 4;


//     int maxEle = maxi(arr,n);
//     int miniEle = mini(arr,n);

//     for(int i = 1; i <= maxEle-miniEle; ++i)
//     {
//         if(canWePlace(arr,n,i,cows) == true)
//         {
//             continue;
//         }else{
//             ans = i - 1;
//             break;
//         }
//     }

//     // T.C => O(maxi-mini) * O(n)
//     // S.C => O(1)
//     cout << ans << endl;
//     return 0;
// }

// Optimal Approach

#include<bits/stdc++.h>
using namespace std;

bool canWePlace(int* arr,int n,int dist,int cows)
{
    int cnt_cows = 1;
    int last = arr[0];

    for(int i = 1; i < n; ++i)
    {
        if(arr[i] - last >= dist)
        {
            cnt_cows++;
            last = arr[i];
        }

        if(cnt_cows >= cows)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        int cows;
        cin >> n >> cows;
        int arr[n];
        for(int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }

        sort(arr,arr+n);

       int maxEle = arr[n-1];
       int minEle = arr[0];

       int start = 1;
       int end = maxEle - minEle;

       while(start <= end)
       {
        int mid = start + (end - start)/2;

        if(canWePlace(arr,n,mid,cows) == true)
        {
            start = mid + 1;
        }else {
            end = mid - 1;
        }
       }

       cout << end << endl;
    }
    
    return 0;
}