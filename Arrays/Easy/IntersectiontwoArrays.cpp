// Intersection of two arrays
// A[] = {1,2,2,3,3,4,5,5,6}
// B[] = {2,3,3,5,6,6,7}
// Intersection -> {2,3,3,5,6}

// Brute Force Approach
// T.C => O(n1 * n2)
// S.C => O(n2)
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int arr1[] = {1,2,2,3,3,4,5,5,6};
//     int n1 = sizeof(arr1)/sizeof(arr1[0]);

//     int arr2[] = {2,3,3,5,6,6,7};
//     int n2 = sizeof(arr2)/sizeof(arr2[0]);

//     int vis[n2];

//     vector<int> ans;

//     for(int i = 0; i < n1; ++i)
//     {
//         for(int j = 0; j < n2; ++j)
//         {
//             if(arr1[i] == arr2[j] && vis[j] == 0)
//             {
//                 ans.push_back(arr2[j]);
//                 vis[j] = 1;
//                 break;
//             }

//             if(arr2[j] > arr1[i]){
//                 break;
//             }
//         }
//     }

//     for(int ele : ans)
//     {
//         cout << ele << " ";
//     }

#include<bits/stdc++.h>
using namespace std;
int main()
{
    // Optimized Approach

    int arr1[] = {1,2,2,3,3,4,5,5,6};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);

    int arr2[] = {2,3,3,5,6,6,7};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    int i = 0;
    int j = 0;

    vector<int> intersect;

    while(i < n1 && j < n2)
    {
        if(arr1[i] < arr2[j]){
            i++;
        }else if(arr2[j] < arr1[i]){
            j++;
        }else {
            intersect.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    for(int ele : intersect)
    {
        cout << ele << " ";
    }

    // T.C => O(n1 + n2)
    // S.C => (1) , used O(n1 + n2) in order to return an answer

    return 0;
}