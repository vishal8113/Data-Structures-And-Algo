// Given an array, range 1 to N
// Find the all duplicates in an array
// ex :- {2,3,5,3,2};
// ans = {2,3}

//Brute Force
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2,3,5,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> ans;
    for(int i = 1; i <= n; ++i) // O(n)
    {
        int cnt = 0;
        for(int j = 0; j < n; ++j)  // O(n)
        {
            if(i == arr[j])
            {
                cnt++;
            }
        }

        if(cnt == 2)
        {
            ans.push_back(i);
        }
    }

    // T.C => O(n*n) => O(n^2)
       S.C => O(1)

    for(int ele : ans)
    {
        cout << ele << " ";
    }
    
    return 0;
}

// Better Solution
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2,3,5,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    unordered_map<int,int> m;

    for(int i = 0; i < n; ++i)  // O(n)
    {
        m[arr[i]]++; // O(1)
    }
    
    vector<int> ans;
    
    for(auto it : m)  // o(n) (In worst case)
    {
        if(it.second == 2)
        {
            ans.push_back(it.first);
        }
    }

    // T.C => O(n) + O(n) => O(2n)
    // S.C => O(n)

    for(int ele : ans)
    {
        cout << ele << " ";
    }
    return 0;
}

// There are 2 optimal solutions of this question
// one is using cyclic sort
// another one is counting sort

// Using cyclic sort
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2,3,5,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    int i = 0;
    while(i < n) // O(n)
    {
        int correctIndex = arr[i] - 1;

        if(i != correctIndex && arr[correctIndex] != correctIndex + 1)
        {
            swap(arr[i],arr[correctIndex]);
        }else {
            i++;
        }
    }

    vector<int> ans;

    for(int i = 0; i < n; ++i) // O9n
    {
        if(arr[i] != i + 1)
        {
            ans.push_back(arr[i]);
        }
    }

    for(int ele : ans)
    {
        cout << ele << " ";
    }
    return 0;
}

// Using Counting Sort
// we will go through each array index by doing %n
// we will add n at the index array value
// After this , we will divide each element of an array by n
// If the answer we greater than 2, then we can say that particular 
// element was duplicate

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2,3,5,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i < n; ++i)  // O(n)
    {
        int index = (arr[i] - 1) % n;
        arr[index]+=n;
    }

    vector<int> ans;

    for(int i = 0; i < n; ++i)  // O(n)
    {
        if(arr[i] >= 2 * n)
        {
            ans.push_back(i+1);
        }
    }

    // T.C => (2n)
    // S.C => O(n)

    for(int ele : ans)
    {
        cout << ele << " ";
    }
}
