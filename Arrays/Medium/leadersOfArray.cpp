// find the leaders in an array
// The leaders in an array are those element whose have only 
// smaller elements in the right
// Ex: [10,22,12,3,0,6]
// ans = [22,12,6]

// Brute Force

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {10,22,12,3,0,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> ans;

    for(int i = 0; i < n; ++i)  // O(n)
    {
        bool leader = true;
        for(int j = i + 1; j < n; ++j)  // O(n)
        {
            if(arr[j] > arr[i]){
                leader = false;
                break;
            }
        }

         if(leader == true)
        {
            ans.push_back(arr[i]);
        }
    }

    for(int ele : ans)
    {
        cout << ele << " ";
    }

    // T.C => O(n*n)
    // S.C => O(1)

    return 0;
}

// Optimal Solution

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {10,22,12,3,0,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    int maxi = INT_MIN;

    vector<int> ans;

    for(int i = n - 1; i >= 0; --i)  // O(n)
    {
        if(arr[i] > maxi)
        {
            ans.push_back(arr[i]);
        }
        maxi = max(maxi,arr[i]);
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