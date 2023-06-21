// Longest subarray length with given sum k (only 0s and +ves)
// ex: arr[] = {1,2,3,1,1,1,14,2,3}
// ans = 3


Brute Force
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int given = 3;

    int len = 0;
    for (int i = 0; i < n; ++i)  // O(n)
    {
        int sum = 0;
        for (int j = i; j < n; ++j) // O(n)
        {
            
            sum+=arr[j];
            if(sum == given)
            {
                len = max(len, j-i+1);
            }
        }
    }

    // T.C => O(n^2)
    // S.C => O(1)

    cout << len << endl;
    return 0;
}

// Better Approach

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 3;

    map<int,int> m;
    int prefixSum = 0;
    int maxLen = 0;

    for(int i = 0; i < n; ++i)  // O(n)
    {
        prefixSum+=arr[i];
        if(prefixSum == k)
        {
            maxLen = max(maxLen,i+1);
        }

        int rem = prefixSum - k;
        if(m.find(rem) != m.end())
        {
            int len = i - m[rem];
            maxLen = max(maxLen,len);
        }

        if(m.find(prefixSum) == m.end())
        {
            m[prefixSum] = i;
        }
    }

    // T.C => O(nlogn)
    // S.C => O(1)

    cout << maxLen << " ";
    return 0;
}


// Optimal Approach

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 3;

    int left = 0;
    int right = 0;

    int sum = arr[0];

    int len = 0;

    while(right < n)  // O(n)
    {
        while(left <= right && sum > k) // overall n
        {
            sum -= arr[left];
            left++;
        }

        if(sum == k)
        {
            len = max(len,right - left + 1);
        }
        right++;
        if(right < n) sum+=arr[right];
    }

    // T.C => O(2N)
    // S.C => O(1)

    cout << len << endl;
    return 0;
}




