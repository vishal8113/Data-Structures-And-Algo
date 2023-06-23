// ex : arr = [3,1,-2,-5,2,-4]
// ans = [3,-2,1,-5,2,-4]

// Brute Force

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {3,1,-2,-5,2,-4};
    int n = sizeof(arr)/sizeof(arr[0]);

    int pos[n/2] = {0};
    int neg[n/2] = {0};

    int idx = 0,idx1 =0;
    for(int i = 0; i < n; ++i)
    {
        if(arr[i] < 0)
        {
            neg[idx] = arr[i];
            idx++;
        } else{
            pos[idx1] = arr[i];
            idx1++;
        }
    }

    for(int i = 0; i < n/2; ++i)
    {
        arr[2*i] = pos[i];
        arr[2*i+1] = neg[i];
    }

    for(int ele : arr)
    {
        cout << ele << " ";
    }
    cout << endl;

    // T.C => O(n) + O(n/2)
    // S.C => O(n)
    return 0;
}


// Optimal Solution

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {3,1,-2,-5,2,-4};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> ans(n,0);
    int posIndex = 0;
    int negIndex = 1;

    for(int i = 0; i < n; ++i)
    {
        if(arr[i] < 0)
        {
            ans[negIndex] = arr[i];
            negIndex+=2;
        } else {
            ans[posIndex] = arr[i];
            posIndex+=2;
        }
    }

    for(int ele : ans)
    {
        cout << ele << " ";
    }
    cout << endl;

    // T.C => O(n)
    // S.C => O(1)
    return 0;
}


