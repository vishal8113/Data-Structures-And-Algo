// arr = {7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5} 
// Majority element is that element which appears more than n/2 times
// ans is 5 in that example

// Brute Force
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = 0;

    for(int i = 0; i < n; ++i)  // O(n)
    {
        int cnt = 0;
        for(int j = 0; j < n; ++j){  // O(n)
            if(arr[i] == arr[j]){
                cnt++;
            }

            if(cnt > n/2)
            {
                ans = arr[j];
            }
        }
    }

    // T.C => O(N*N) => O(n^2)
    // S.C => O(1)

    cout << ans << endl;

    return 0;
}

// Optimal Solution
#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<int,int> m;

    int arr[] = {7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i < n; ++i)  // O(n)
    {
        m[arr[i]]++;
    }

    int k = n/2;
    for(auto it : m)  // O(1)
    {
        if(it.second > k)
        {
            cout << it.first << endl;
            break;
        }
    }

    // T.C => O(n)
    // S.C => O(n)

    return 0;
}

// Optimized Approach
// Uses Moore's Voting Algorithm

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    int cnt = 0;
    int ele;

    for(int i = 0; i < n; ++i)  // O(n)
    {
        if(cnt == 0)
        {
            cnt++;
            ele = arr[i];
        }else if(arr[i] == ele)
        {
            cnt++;
        }else{
            cnt--;
        }
    }

    int cnt1 = 0;
    for(int i = 0; i < n; ++i) // O(n)
    {
        if(arr[i] == ele)
        {
            cnt1++;
        }
    }

    if(cnt1 > (n/2)){
        cout << ele << endl;
    }

    // T.C => O(2N)
    // S.C +> O(1)
    return 0;
}