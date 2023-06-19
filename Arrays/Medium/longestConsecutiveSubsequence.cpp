// Longest Consecutive Sequence

// Ex:- arr[] = {102,4,100,1,101,3,2,1,1}
// ans = 4

// Brute Force
// #include<bits/stdc++.h>
// using namespace std;
// bool linearSearch(int arr[],int n,int target) 
// { 
//     for(int i = 0; i < n; ++i) // O(n)
//     {
//         if(arr[i] == target)
//         {
//             return true;
//         }
//     }

//     return false;
// }
// int main()
// {
//     int arr[] = {102,4,100,1,101,3,2,103,104};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     int longest = 1;

//     for(int i = 0; i < n; ++i) // O(n)
//     {
//         int x = arr[i];
//         int cnt = 1;
//         while(linearSearch(arr,n,x+1) == true){
//             x = x+1;
//             cnt++;

//             longest = max(longest,cnt);
//         }
//     }

//     // T.C => O(n^2)
//     // S.C => O(1)

//     cout << longest << endl;
//     return 0;
// }

// Better Solution

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int arr[] = {102,4,100,1,101,3,2,103,104};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     sort(arr,arr+n);  // O(nLOgn)

//     int largest = 1;
//     int currCnt = 0;
//     int last_smaller = INT_MIN;

//     for(int i = 0; i < n; ++i) // O(n)
//     {
//         if(arr[i] - 1 == last_smaller)
//         {
//             currCnt = currCnt + 1;
//             last_smaller = arr[i];
//         }else if(arr[i] != last_smaller)
//         {
//             currCnt = 1;
//             last_smaller = arr[i];
//         }

//         largest = max(largest,currCnt);
//     }

//     // T.C => O(nlogn) + O(n)
//     // S.C => O(1)

//     cout << largest << endl;
//     return 0;
// }

// Optimal Approach

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {6,102,4,100,1,101,3,25,2,103,5,104};
    int n = sizeof(arr)/sizeof(arr[0]);

    unordered_set<int> st;
    int longest = 1;

    for(int i = 0; i < n; ++i) // O(n)
    {
        st.insert(arr[i]);
    }

    for(auto it : st)  // O(2N)
    {
        if(st.find(it-1) == st.end())
        {
            int cnt = 1;
            int x = it;
            while(st.find(x+1) != st.end())
        {
            x = x + 1;
            cnt = cnt + 1;
        }
        longest = max(longest,cnt);
        }
    }

    // T.C => O(n) + O(2N)
    // S.C => O(n)

    cout << longest << endl;
    return 0;
}