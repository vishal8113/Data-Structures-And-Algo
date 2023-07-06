// Kth Element of two sorted arrays

// arr1 = {1,3,4,7,10,12}
// arr2 = {2,3,6,15}

// ans = 6

// Brute Force

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int arr1[] = {1,3,4,7,10,12};
//     int arr2[] = {2,3,6,15};

//     int k = 5;

//     int n = sizeof(arr1)/sizeof(arr1[0]);
//     int m = sizeof(arr2)/sizeof(arr2[0]);

//     int i = 0;
//     int j = 0;
//     int cnt = 0;

//     int ans = INT_MIN;

//     while(i < n && j < m)
//     {
//         if(cnt == k)
//         {
//             break;
//         }else if(arr1[i] < arr2[j])
//         {
//             ans = arr1[i];
//             ++i;
//         } else {
//             ans = arr2[j];
//             ++j;
//         }
//         ++cnt;
//     }

//     cout << ans << endl;

//     // T.C => O(k)
//     // S.C => O(1)

//     return 0;
// }

// Binary Search Approach

#include<bits/stdc++.h>
using namespace std;

int find(vector<int> &arr1,vector<int> &arr2,int k){
    if(arr1.size() > arr2.size())
    {
        return find(arr2,arr1,k);
    }

    int n = arr1.size();
    int m = arr2.size();

    int start = max(0,k-m);
    int end = min(k,n);

    while(start <= end)
    {
        int cut1 = (start + end) >> 1;
        int cut2 = k - cut1;

        int left1 = cut1 == 0 ? INT_MIN : arr1[cut1-1];
        int left2 = cut2 == 0 ? INT_MIN : arr2[cut2-1];
        int right1 = cut1 == n ? INT_MAX : arr1[cut1];
        int right2 = cut2 == m ? INT_MAX : arr2[cut2];

        if(left1 <= right2 && left2 <= right1)
        {
            return max(left1,left2);
        } else if(left1 > right2)
        {
            end = cut1 - 1;
        }else {
            start = cut1 + 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr1 = {2,3,6,7,9};
    vector<int> arr2 = {1,4,8,10};

    int k = 5;

    int ans = find(arr1,arr2,k);

    cout << ans << endl;
    return 0;
}
