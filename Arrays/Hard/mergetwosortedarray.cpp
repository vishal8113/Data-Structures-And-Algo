// Merge Two Sorted Arrays without Extra Space

// int arr1[] = {1,3,5,7}
// int arr2[] = {0,2,6,8,9}

// ans = arr1 = 0 1 2 3   
//       arr2 = 5 6 7 8 9

// Brute Force

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr1[] = {1,3,5,7};
    int arr2[] = {0,2,6,8,9};

    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);

    int arr3[n+m];
    int k = sizeof(arr3)/sizeof(arr3[0]);

    int left = 0;
    int right = 0;
    int index = 0;
    while(left < n && right < m)
    {
        if(arr1[left] <= arr2[right])
        {
            arr3[index] = arr1[left];
            left++;
            index++;
        } else{
            arr3[index] = arr2[right];
            right++;
            index++;
        }
    }

    while(left < n)
    {
        arr3[index++] = arr1[left++];
    }

    while(right < m)
    {
        arr3[index++] = arr2[right++];
    }

    for(int i = 0; i < k; ++i)
    {
        if(i < n)
        {
            arr1[i] = arr3[i];
        }else{
            arr2[i-n] = arr3[i];
        }
    }

    for(int ele : arr1)
    {
        cout << ele << " ";
    }
    cout << endl;

    for(int ele : arr2)
    {
        cout << ele << " ";
    }
    cout << endl;

    // T.C => O(n+m) + O(n+m)
    // S.C => O(n+m)
    return 0;
}


// Optimal Approach

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr1[] = {1,3,5,7};
    int arr2[] = {0,2,6,8,9};

    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);

    int left = n - 1;
    int right = 0;

    while(left >= 0 && right < m)
    {
        if(arr1[left] > arr2[right])
        {
            swap(arr1[left],arr2[right]);
            left--;
            right++;
        } else{
            break;
        }
    }

    sort(arr1,arr1+n);
    sort(arr2,arr2+m);

    for(int ele : arr1)
    {
        cout << ele << " ";
    }
    cout << endl;

    for(int ele : arr2)
    {
        cout << ele << " ";
    }
    cout << endl;

    // T.C => O(min(n,m)) + O(nlogn) + O(mlogn)
    // S.C => O(1)

    return 0;
}


// More Optimal Solution

#include<bits/stdc++.h>
using namespace std;
void swapfunc(int* arr1,int* arr2,int idx1,int idx2)
{
    if(arr1[idx1] > arr2[idx2])
    {
        swap(arr1[idx1],arr2[idx2]);
    }
}
int main()
{
    int arr1[] = {1,3,5,7};
    int arr2[] = {0,2,6,8,9};

    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);

    int len = n+m;
    int gap = (len/2) + (len%2);

    while(gap > 0)
    {
        int left = 0;
        int right = left + gap;

        while(right < len)
        {
            if(left < n && right >= n){
                swapfunc(arr1,arr2,left,right-n);
            } else if(left >= n) {
                swapfunc(arr2,arr2,left-n,right-n);
            } else {
                swapfunc(arr1,arr1,left,right);
            }
            left++;
            right++;
        }

        if(gap == 1)
        {
            break;
        }
        gap = (gap/2) + (gap%2);
    }

    for(int ele : arr1)
    {
        cout << ele << " ";
    }
    cout << endl;

    for(int ele : arr2)
    {
        cout << ele << " ";
    }
    cout << endl;

    // T.C => O(log2(n+m)) * O(n+m)
    // S.C => O(1)
    return 0;
}
