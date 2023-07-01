// Allocate Books Problem

// Brute Force

// #include<bits/stdc++.h>
// using namespace std;

// int maxi(int* arr,int n)
// {
//     int k = arr[0];
//     for(int i = 1;i < n; ++i)
//     {
//         if(arr[i] > k)
//         {
//             k = arr[i];
//         }
//     }

//     return k;
// }

// int fn(int* arr,int n,int pages)
// {
//     int student = 1;
//     int pageHold = 0;

//     for(int i = 0; i < n; ++i)
//     {
//         if(pageHold + arr[i] <= pages)
//         {
//             pageHold+=arr[i];
//         }else{
//             student++;
//             pageHold = arr[i];
//         }
//     }

//     return student;
// }

// int main()
// {
//     int arr[] = {25,46,28,49,24};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     int students = 4;
//     int ans = -1;

//     if(students > n)
//     {
//         ans = -1;
//     }

//     int maxEle = maxi(arr,n);

//     int sum = accumulate(arr,arr+n,0);

//     for(int pages = maxEle; pages <= sum; ++pages)
//     {
//         int cntStudent = fn(arr,n,pages);

//         if(cntStudent == students)
//         {
//             ans = pages;
//             break;
//         }
//     }

//     // T.C => O(sum-maxi+1) * O(n)
//     // S.C => O(1)

//     cout << ans << endl;
//     return 0;
// }

// Optimal (Binary search)

#include<bits/stdc++.h>
using namespace std;

int maxi(int* arr,int n)
{
    int k = arr[0];
    for(int i = 1;i < n; ++i)
    {
        if(arr[i] > k)
        {
            k = arr[i];
        }
    }

    return k;
}

int fn(int* arr,int n,int pages)
{
    int student = 1;
    int pageHold = 0;

    for(int i = 0; i < n; ++i)
    {
        if(pageHold + arr[i] <= pages)
        {
            pageHold+=arr[i];
        }else{
            student++;
            pageHold = arr[i];
        }
    }

    return student;
}

int main()
{
    int arr[] = {25,46,28,49,24};
    int n = sizeof(arr)/sizeof(arr[0]);

    int students = 4;
    int ans = -1;

    if(students > n)
    {
        ans = -1;
    }
    
    int maxEle = maxi(arr,n);

    int sum = accumulate(arr,arr+n,0);

    int start = maxEle;
    int end = sum;

    while(start <= end)
    {
        int mid = start + (end - start)/2;
        int cntStudent = fn(arr,n,mid);
        if(cntStudent > students)
        {
            start = mid + 1;
        }else {
            end = mid - 1;
        }
    }

    cout << start << endl;

    return 0;
}